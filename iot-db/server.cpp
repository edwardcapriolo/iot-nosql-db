#include "server.h"

server::server() {
}

server::server(const server& orig) {
}

server::~server() {
}

void serv(event_based_actor* self, server* server) {
    
     //std::map<string,string> kv;

     self->become (
         on<write_request>() >> [=]( write_request& val) {
             cout << val.key
             << val.column << ", "
             << val.value << ")"
             << endl;
             server->getX();
             //kv.insert( std::pair<string,string>("a", "b"));
             return "abc";
         },
         on<shutdown_request>() >> [=] (shutdown_request& val) {
             self->quit();
             return "";
         }
     );
 }
