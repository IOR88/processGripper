#include <sys/types.h>
#include <sys/socket.h>

//#include "PgSocketBaseClass.hpp"
#include "PgSocketServerClass.hpp"


PgSocketServerClass::PgSocketServerClass(int domain, int type, int protocol)
    :PgSocketBaseClass(domain, type, protocol){

}

PgSocketServerClass::~PgSocketServerClass(){

}

void PgSocketServerClass::pg_bind(const sockaddr * address){

    int bind_s = bind ( this->sock_d, address, sizeof( address ) );

    if ( bind_s < 0 ) {
        throw -1;
    }

}