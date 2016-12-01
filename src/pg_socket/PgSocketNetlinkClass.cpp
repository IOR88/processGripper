#include <linux/netlink.h>
#include <linux/connector.h>

#include "PgSocketNetlinkClass.hpp"

PgSocketNetlinkClass::PgSocketNetlinkClass(int domain, int type, int protocol)
    :PgSocketServerClass(domain, type, protocol){

}


PgSocketNetlinkClass::~PgSocketNetlinkClass(){

}

void PgSocketNetlinkClass::pg_fill_address(){

}