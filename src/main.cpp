#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <linux/netlink.h>
#include <linux/connector.h>
#include <linux/cn_proc.h>

#include "pg_socket/PgSocketNetlinkClass.hpp"

int main(){

    //constructor//
    PgSocketNetlinkClass sn = PgSocketNetlinkClass();

    //errors www.virtsync.com/c-error-codes-include-errno
    //http://man7.org/linux/man-pages/man3/errno.3.html

    //create socket descriptor//
    try {
        sn.pg_create_socket_d(AF_NETLINK, SOCK_DGRAM, NETLINK_CONNECTOR);
        std::cout << "OK:: socket creation"  << std::endl;
    } catch(int e){
        std::cout << "ERROR:: socket creation " << strerror(errno)  << std::endl;
    };

    //create client address structure//
    sn.pg_create_address(AF_NETLINK, 0, getpid(), CN_IDX_PROC);

    //bind socket//
    try {
        sn.pg_bind((struct sockaddr *) &sn.address, sizeof sn.address);
        std::cout << "OK:: socket binding"  << std::endl;
    } catch(int e){
        std::cout << "ERROR:: socket binding " << strerror(errno)  << std::endl;

    }

    //create netlink and connector headers//
    //subscribe//

}