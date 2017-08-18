// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "EchoTest.h"
#include <thrift/protocol/TJSONProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <iostream>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::demo;

class EchoTestHandler : virtual public EchoTestIf {
 public:
  EchoTestHandler() {
    // Your initialization goes here
  }

  void echo(std::string& _return, const std::string& str) {
    // Your implementation goes here
    std::cerr << "echo " << str << "\n";
    _return = str;
  }

};

int main(int argc, char **argv) {

  int port = 9090;

  if (argc == 2) {
    int tmp = atoi(argv[1]);
    if (tmp != 0) port = tmp;
  }

  shared_ptr<EchoTestHandler> handler(new EchoTestHandler());
  shared_ptr<TProcessor> processor(new EchoTestProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TJSONProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

