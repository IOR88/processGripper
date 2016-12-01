#include <linux/netlink.h>
#include <linux/connector.h>

#include "PgSocketServerClass.hpp"

class PgSocketNetlinkClass: protected PgSocketServerClass {

    private:
        struct sockaddr_nl address;

    public:
        PgSocketNetlinkClass(int domain, int type, int protocol);
        ~PgSocketNetlinkClass();

        void pg_fill_address();


};