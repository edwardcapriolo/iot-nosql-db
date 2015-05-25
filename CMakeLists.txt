cmake_minimum_required(VERSION 2.8)
add_definitions(-std=c++11)
project (iot-nosql-db)

add_subdirectory (iot-db)
add_subdirectory (tests)

set(CMAKE_BUILD_TYPE Debug)
