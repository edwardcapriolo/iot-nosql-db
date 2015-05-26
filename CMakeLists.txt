cmake_minimum_required(VERSION 2.8)
add_definitions(-std=c++11)
project (iot-nosql-db)

list(APPEND ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(Libcaf COMPONENTS core REQUIRED)
find_package(cppunit REQUIRED)

include_directories(. include ${CMAKE_BINARY_DIR} ${LIBCAF_INCLUDE_DIRS})

add_subdirectory (iot-db)
add_subdirectory (tests)

set(CMAKE_BUILD_TYPE Debug)


