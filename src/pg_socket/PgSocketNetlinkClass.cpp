#include <linux/netlink.h>
#include <linux/connector.h>

#include "PgSocketNetlinkClass.hpp"

PgSocketNetlinkClass::PgSocketNetlinkClass(){

}


PgSocketNetlinkClass::~PgSocketNetlinkClass(){

}

void PgSocketNetlinkClass::pg_fill_address(
                sa_family_t nl_family,
                unsigned short nl_pad,
                pid_t nl_pid,
                __u32 nl_group){

    this->address={
        nl_family,
        nl_pad,
        nl_pid,
        nl_group
    };

}

void PgSocketNetlinkClass::pg_subscribe(){

}