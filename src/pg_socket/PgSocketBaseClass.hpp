#include <sys/types.h>
#include <sys/socket.h>

class PgSocketBaseClass {

    protected:
        int sock_d;

    public:
        PgSocketBaseClass(int domain, int type, int protocol);
        ~PgSocketBaseClass();

};