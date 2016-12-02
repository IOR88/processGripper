#include <linux/netlink.h>
#include <linux/connector.h>

#include "PgSocketNetlinkClass.hpp"

PgSocketNetlinkClass::PgSocketNetlinkClass(){

}


PgSocketNetlinkClass::~PgSocketNetlinkClass(){

}

void PgSocketNetlinkClass::pg_create_address(
                            sa_family_t nl_family,
                            unsigned short nl_pad,
                            __u32 nl_pid,
                            __u32 nl_group){

    this->address={
        nl_family,
        nl_pad,
        nl_pid,
        nl_group
    };

}

void PgSocketNetlinkClass::pg_create_msg_header(
                                  __u32 nlmsg_len,
                                  __u16 nlmsg_type,
                                  __u16 nlmsg_flags,
                                  __u32 nlmsg_seq,
                                  __u32 nlmsg_pid){
  /* Length of message */
  /* Message type*/
  /* Additional flags */
  /* Sequence number */
  /* Sending process PID */

    this->msg_header={
        nlmsg_len,
        nlmsg_type,
        nlmsg_flags,
        nlmsg_seq,
        nlmsg_pid
    };

}

void PgSocketNetlinkClass::pg_initiate_mode(){
    /*subscribe on processes events*/
    /*Fast Scatter-Gather I/O IOVEC
      http://www.gnu.org/software/libc/manual/html_node/Scatter_002dGather.html
      http://www.gnu.org/software/libc/manual/html_node/POSIX-Safety-Concepts.html#POSIX-Safety-Concepts*/
}