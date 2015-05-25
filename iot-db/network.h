#include <string.h>
#include <iostream>

#ifndef NETWORK_H
#define	NETWORK_H

using namespace std;

struct write_request {
    string key;
    string column;
    string value;
};

struct shutdown_request {
    string why;
};

bool operator==(const shutdown_request& l, const shutdown_request& r);
bool operator==(const write_request& lhs, const write_request& rhs) ;

#endif	/* NETWORK_H */
