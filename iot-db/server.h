#include "caf/all.hpp"
#include "caf/binary_serializer.hpp"
#include "caf/binary_deserializer.hpp"
#include "network.h"

#ifndef SERVER_H
#define	SERVER_H

#include <string.h>
//#include <iostream.h>

using namespace std;
using namespace caf;

class server {
public:
    server();
    server(const server& orig);
    virtual ~server();
    int getX(){
        return 5;
    }    
private:

};

void serv(event_based_actor* self, server* server);
 

#endif	/* SERVER_H */


