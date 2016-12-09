#include <sys/socket.h>
#include <linux/netlink.h>
#include <iostream>
#include <cstring>
#include <stdio.h>
//#include <string.h>
#include <typeinfo>
#include <sys/types.h>
#include <unistd.h>
#include <sys/uio.h>
#include <cerrno>

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

#include <linux/connector.h>
#include <linux/cn_proc.h>

#define MAX_PAYLOAD 1024 /* maximum payload size*/


//THIS EXAMPLE IS WORKING WHEN 69 LINE WAS ADDED  memset(&msg, 0, sizeof(msg)); BEFORE WE WERE GETTING 105 enobuf error

int main()
{
    using namespace std;
    struct sockaddr_nl src_addr, dest_addr;
    struct nlmsghdr *nlh = 0;
    struct iovec iov;
    int sock_fd;
    struct msghdr msg;

    sock_fd = socket(PF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
    if (sock_fd < 0)
        return -1;

    memset(&src_addr, 0, sizeof(src_addr));
    src_addr.nl_family = AF_NETLINK;
    src_addr.nl_pid = getpid(); /* self pid */

    bind(sock_fd, (struct sockaddr *)&src_addr, sizeof(src_addr));

    memset(&dest_addr, 0, sizeof(dest_addr));
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.nl_family = AF_NETLINK;
    dest_addr.nl_pid = 0; /* For Linux Kernel */
    dest_addr.nl_groups = CN_IDX_PROC; /* unicast */

    nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
    memset(nlh, 0, NLMSG_SPACE(MAX_PAYLOAD));
    nlh->nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
    nlh->nlmsg_pid = getpid();
    nlh->nlmsg_flags = 0;

    //strcpy(NLMSG_DATA(nlh), "Hello");

    iov.iov_base = (void *)nlh;
    iov.iov_len = nlh->nlmsg_len;
    msg.msg_name = (void *)&dest_addr;
    msg.msg_namelen = sizeof(dest_addr);
    memset(&msg, 0, sizeof(msg));
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    //printf("Sending message to kernel\n");
    int s = sendmsg(sock_fd, &msg, 0);
    cout << s <<  strerror(errno)  << endl;
    //printf("Waiting for message from kernel\n");

    /* Read message from kernel */
    int r = recvmsg(sock_fd, &msg, 0);
    cout << r <<  strerror(errno)  << endl;
    //printf("Received message payload: %s\n", NLMSG_DATA(nlh));
    cout << NLMSG_DATA(nlh) << " what ? " << endl;
    close(sock_fd);
}