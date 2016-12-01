#include <sys/types.h>
#include <sys/socket.h>
#include "PgSocketServerClass.hpp"


PgSocketServerClass::PgSocketServerClass(){

}

PgSocketServerClass::~PgSocketServerClass(){

}

void PgSocketServerClass::pg_bind(const sockaddr * address, int size) throw(int) {
    //https://linux.die.net/man/2/bind
    int bind_s = bind ( this->sock_d, address, size );

    if ( bind_s < 0 ) {
        throw -1;
    }

}