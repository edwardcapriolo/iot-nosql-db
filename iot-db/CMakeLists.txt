set(CMAKE_BUILD_TYPE Debug)

add_library (iot-db dummy.cpp network.h network.cpp server.cpp server.h)

target_link_libraries (iot-db ${LIBCAF_LIBRARIES})


