#include <unistd.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "wrapunix.h"
#include "wrapsock.h"
#include "wraptermios.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2) {
        cout << "usage: " << argv[0] << " <ttyname1> [ttypname2] [ttyname3] ..." << endl; 
        return 1;
    }

    std::map<int, std::string> tty_map;
    std::vector<struct pollfd> client;

    for (int i = 1; i < argc; i++) {
        int fd = Tty_open_easy(argv[i]);
        cout << "Open tty: " << argv[i] << " ok, " << "fd: " << fd << endl;

        Tty_set_speed(fd, 9600);
        Tty_set_parity(fd, 8, 1, 'N');
        Tty_set_icanon(fd, 0, 0);

        struct pollfd tmp;
        tmp.fd = fd;
        tmp.events = POLLIN;
        tmp.revents = 0;

        client.push_back(tmp);
        tty_map.insert(std::make_pair(fd, std::string(argv[i])));
    }


    int nread;
    const int BUFSIZE = 2048;
    char buff[BUFSIZE];

    string data;
    for ( ; ; ) {
        int nready = Poll(&client[0], client.size(), -1);
        if (nready == 0) {  // timeout
            cerr << ".";
            continue;
        }

        for (int i = 0; i < client.size(); i++) {
            if (client[i].fd < 0) 
                continue;

            if (client[i].revents & POLLIN) {
                nread = read(client[i].fd, buff, BUFSIZE);
                if (nread > 0) {
                    data.assign(buff, nread);
                    cout << "\nread from '" << tty_map[client[i].fd] << "' " << data.size() << " bytes: " << data << endl;
                } else if (nread == 0) {
                    cout << "no data of '" << tty_map[client[i].fd] << "' " << endl;
                    tty_map.erase(client[i].fd);
                    client[i].fd = -1;
                } else {
                    cout << "read error of '" << tty_map[client[i].fd] << "' " 
                        ": " << strerror(errno) << endl;
                    tty_map.erase(client[i].fd);
                    client[i].fd = -1;
                }
            } else if (client[i].revents & POLLERR) {
                cout << "event error of '" << tty_map[client[i].fd] << "' " << endl;
                tty_map.erase(client[i].fd);
                client[i].fd = -1;
            }
        }

        if (tty_map.empty()) {
            cout << "all tty closed!" << endl;
            break;
        }
    }

    for (int i = 0; i < client.size(); i++) {
        close(client[i].fd); 
    }

    return 0;
}
