#include <linux/cn_proc.h>
#include <linux/netlink.h>
#include <linux/connector.h>

#include "PgSocketServerClass.hpp"

class PgSocketNetlinkClass: public PgSocketServerClass {
    /*@idea
      Netlink socket is a special IPC used for transferring information
      between kernel and user-space processes. It provides a full-duplex
      communication link between the two by way of standard socket APIs
      for user-space processes and a special kernel API for kernel modules.
      Netlink socket uses the address family AF_NETLINK, as compared to
      AF_INET used by TCP/IP socket. Each netlink socket feature defines
      its own protocol type in the kernel header file include/linux/netlink.h.*/

    /*@resource:
      http://www.linuxjournal.com/article/7356?page=0,0
      http://man7.org/linux/man-pages/man7/netlink.7.html
      https://people.redhat.com/nhorman/papers/netlink.pdf*/

    public:
        struct sockaddr_nl address;
        struct nlmsghdr msg_header;

        PgSocketNetlinkClass();
        ~PgSocketNetlinkClass();

        void pg_create_address(sa_family_t nl_family,
                               unsigned short nl_pad,
                               __u32 nl_pid,
                               __u32 nl_group);

        void pg_create_msg_header(__u32 nlmsg_len,
                                  __u16 nlmsg_type,
                                  __u16 nlmsg_flags,
                                  __u32 nlmsg_seq,
                                  __u32 nlmsg_pid);

        void pg_initiate_mode();


};