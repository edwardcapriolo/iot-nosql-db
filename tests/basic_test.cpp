#include <cppunit/extensions/HelperMacros.h>
#include "caf/all.hpp"
#include "caf/binary_serializer.hpp"
#include "caf/binary_deserializer.hpp"
#include "server.h"

using namespace std;
using namespace caf;

void client(event_based_actor* self, const actor& buddy) {
  write_request w{ "holly", "age", "4"};
  self->sync_send(buddy, w).then( [=](const string& what) {
      aout(self) << "look what I got " << what << endl;
    }
  );
}

class basic_test : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( basic_test );
  CPPUNIT_TEST( testEmpty );
  CPPUNIT_TEST( testSimple );
  CPPUNIT_TEST_SUITE_END();
public:
  void testEmpty () { 
    int i=5; CPPUNIT_ASSERT(i==5); 
  }

  void testSimple() {
    announce<write_request>(&write_request::key, &write_request::column, &write_request::value);
    announce<shutdown_request>(&shutdown_request::why);
    server * s = new server();
    auto server_actor = spawn (serv, s);
    auto c = spawn (client, server_actor);
    
    shutdown_request r ;
    anon_send( server_actor, r);
    
    await_all_actors_done();
    shutdown();
  }

};
CPPUNIT_TEST_SUITE_REGISTRATION( basic_test );

