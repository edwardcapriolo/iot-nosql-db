enable_testing()
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")

FILE(GLOB UnitTests_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*_test.cpp" )
ADD_EXECUTABLE(UnitTester test_runner.cpp ${UnitTests_SRCS})
FOREACH(test ${UnitTests_SRCS})
        GET_FILENAME_COMPONENT(TestName ${test} NAME_WE)
        add_test(${TestName} UnitTester ${TestName})
ENDFOREACH(test)

include_directories (${PROJECT_SOURCE_DIR}/iot-db ${LIBCAF_INCLUDE_DIRS})

link_directories (${PROJECT_SOURCE_DIR}/iot-db)

target_link_libraries (UnitTester cppunit iot-db ${LIBCAF_LIBRARIES})

