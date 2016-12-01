#include <netinet/in.h>
#include "PgSocketServerClass.hpp"

class PgSocketInternetClass: protected PgSocketServerClass {

    private:
        struct sockaddr_in address;

    public:
        PgSocketInternetClass();
        ~PgSocketInternetClass();

        //todo
        void pg_fill_address();



};