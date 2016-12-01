#include <sys/socket.h>
#include "PgSocketBaseClass.hpp"


PgSocketBaseClass::PgSocketBaseClass(){

}

PgSocketBaseClass::~PgSocketBaseClass(){

}

void PgSocketBaseClass::pg_create_socket_d(int domain, int type, int protocol) throw(int){
    /* creates socket descriptor */

    this->sock_d = socket(domain, type, protocol);

    if ( this->sock_d < 0 ) {
        throw -1;
    }

}

