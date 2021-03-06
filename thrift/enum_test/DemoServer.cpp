// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "DemoService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class DemoServiceHandler : virtual public DemoServiceIf {
 public:
  DemoServiceHandler() {
    // Your initialization goes here
  }

   ::ErrorType::type query(const std::string& req) {
    // Your implementation goes here
    printf("query\n");
    return (::ErrorType::type) 15;
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<DemoServiceHandler> handler(new DemoServiceHandler());
  shared_ptr<TProcessor> processor(new DemoServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

