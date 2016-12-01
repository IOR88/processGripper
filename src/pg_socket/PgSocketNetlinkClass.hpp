#include <linux/netlink.h>
#include <linux/connector.h>

#include "PgSocketServerClass.hpp"

class PgSocketNetlinkClass: public PgSocketServerClass {
    //http://man7.org/linux/man-pages/man7/netlink.7.html

    public:
        struct sockaddr_nl address;
        /*The sockaddr_nl structure describes a netlink client in user space or in the kernel.*/

        PgSocketNetlinkClass();
        ~PgSocketNetlinkClass();

        void pg_fill_address(
                sa_family_t nl_family,
                unsigned short nl_pad,
                pid_t nl_pid,
                __u32 nl_group);

        void pg_subscribe();


};