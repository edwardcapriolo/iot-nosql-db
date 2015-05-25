#include <cppunit/extensions/HelperMacros.h>
#include "caf/all.hpp"
#include "caf/binary_serializer.hpp"
#include "caf/binary_deserializer.hpp"
#include "server.h"

using namespace std;
using namespace caf;

class basic_test : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( basic_test );
  CPPUNIT_TEST( testEmpty );
  CPPUNIT_TEST( testSimple );
  CPPUNIT_TEST_SUITE_END();
public:
  void testEmpty () { int i=5; CPPUNIT_ASSERT(i==5); }
void testSimple() {
    announce<write_request>(&write_request::key, &write_request::column, &write_request::value);
    announce<shutdown_request>(&shutdown_request::why);
    server * s = new server();
    auto a = spawn (serv, s);
    shutdown_request r ;
    anon_send( a, r);
    await_all_actors_done();
    shutdown();

}

};
CPPUNIT_TEST_SUITE_REGISTRATION( basic_test );

