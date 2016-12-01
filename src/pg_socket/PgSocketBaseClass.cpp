#include "PgSocketBaseClass.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <iostream>

PgSocketBaseClass::PgSocketBaseClass(int domain, int type, int protocol){
    /* creates socket descriptor */

    this->sock_d = socket(domain, type, protocol);

    if ( this->sock_d < 0 ) {
        throw -1;
    }

}

PgSocketBaseClass::~PgSocketBaseClass(){

}


//PgSocketClass::pg_fill_address(){
////netlink - communication between kernel and user space (AF_NETLINK)
////To select the proc connector we bind the socket using a struct sockaddr_nl object.
////addr.nl_family = AF_NETLINK;
////addr.nl_pid = getpid ();
////addr.nl_groups = CN_IDX_PROC;
//
//
//
////http://www.ccplusplus.com/2011/10/struct-sockaddrin.html
////http://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html
////Structures for handling internet addresses
////struct sockaddr_in {
////    short            sin_family;   // e.g. AF_INET
////    unsigned short   sin_port;     // e.g. htons(3490)
////    struct in_addr   sin_addr;     // see struct in_addr, below
////    char             sin_zero[8];  // zero this if you want to
////};
//
//
//
//}

