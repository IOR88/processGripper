class PgSocketBaseClass {

    protected:
        int sock_d;

    public:
        PgSocketBaseClass();
        ~PgSocketBaseClass();
        void pg_create_socket_d(int domain, int type, int protocol) throw(int);

};