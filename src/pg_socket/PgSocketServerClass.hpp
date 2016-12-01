#include "PgSocketBaseClass.hpp"
#include <sys/types.h>
#include <sys/socket.h>

class PgSocketServerClass : public PgSocketBaseClass {


    public:
        PgSocketServerClass();
        ~PgSocketServerClass();
        void pg_bind(const sockaddr * address, int size) throw(int);



};