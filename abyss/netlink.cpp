#include <sys/socket.h>
#include <linux/netlink.h>
#include <linux/cn_proc.h>
#include <iostream>
#include <typeinfo>
#include <sys/types.h>
#include <unistd.h>
#include <sys/uio.h>
#include <cerrno>
#include <string.h>

#define NLINK_MSG_LEN 1024

using namespace std;

int main(){



    //<==initialize socket==>//
    struct socket_s {
        int domain;
        int type;
        int protocol;
    };

    struct socket_s socket_init = {PF_NETLINK, SOCK_DGRAM, NETLINK_ROUTE};

    int sd = socket(socket_init.domain, socket_init.type, socket_init.protocol);

    if (sd < 0){
        cout << strerror(errno) << endl;
    }
    //<==initialize socket==>//



    //<==bind socket==>//
    struct sockaddr_nl src_addr;

    src_addr.nl_family = AF_NETLINK;
    src_addr.nl_pid = getpid();
    src_addr.nl_groups = 0;

    int bind_error = bind(sd, (struct sockaddr *) &src_addr , sizeof(src_addr));

    if (bind_error < 0){
        cout << strerror(errno) << endl;
    }
    //<==bind socket==>//



    //<==subscribe==>//
    struct sockaddr_nl dest_addr;

    dest_addr.nl_family = AF_NETLINK;
    dest_addr.nl_pid = 0; //linux kernel
    dest_addr.nl_groups = 0; //unicast

    nlmsghdr nlmsghdrbuf[NLMSG_LENGTH (0)];
    struct nlmsghdr *nlh = nlmsghdrbuf;
    nlh->nlmsg_len = NLMSG_SPACE(1024); //todo
    nlh->nlmsg_pid = getpid();
    nlh->nlmsg_flags = 0;

    struct iovec iov[0];
    iov[0].iov_base = (void *)nlh;
    iov[0].iov_len = nlh->nlmsg_len;


    struct msghdr msg;
    msg.msg_name = (void *)&dest_addr;
    msg.msg_namelen = sizeof(dest_addr);
    msg.msg_iov = &iov[0];
    msg.msg_iovlen = 1;

    cout << sizeof(msg) << endl;
    int sc = sendmsg(sd, &msg, 0);

    if (sc < 0){
        cout << errno << endl;
        cout << strerror(errno) << endl;
    }
    //<==subscribe==>//




    //received//
//    struct sockaddr_nl nladdr;
//    //struct msghdr msg;
//    //struct iovec iov;
//
//    iov.iov_base = (void *)nlh;
//    iov.iov_len = NLINK_MSG_LEN;
//    msg.msg_name = (void *)&(nladdr);
//    msg.msg_namelen = sizeof(nladdr);
//
//    msg.msg_iov = &iov;
//    msg.msg_iovlen = 1;
//
//    for (;;){
//        int rc = recvmsg(sd, &msg, 0);
//        cout << rc << endl;
//
//    };
//
//
//
//    /* Close Netlink Socket */
//    close(sd);


}