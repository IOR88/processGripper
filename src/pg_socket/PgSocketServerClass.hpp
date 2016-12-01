#include "PgSocketBaseClass.hpp"
#include <sys/types.h>
#include <sys/socket.h>

class PgSocketServerClass : protected PgSocketBaseClass {


    public:
        PgSocketServerClass(int domain, int type, int protocol);
        ~PgSocketServerClass();
        void pg_bind(const sockaddr * address);



};