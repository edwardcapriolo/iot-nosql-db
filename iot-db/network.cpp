#include "network.h"

bool operator==(const write_request& lhs, const write_request& rhs) {
  return  lhs.key == rhs.key
       && lhs.column == rhs.column;
}

bool operator==(const shutdown_request& l, const shutdown_request& r){
  return l.why == r.why;  
}
