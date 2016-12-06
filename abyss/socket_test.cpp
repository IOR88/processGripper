#include <sys/socket.h>
#include <linux/netlink.h>
#include <iostream>
#include <typeinfo>
//class

class ProtocolInterface {

    public:
        virtual void get_socket_d_info() const = 0;
        virtual void get_header_info() const = 0;
        //initialization_msg//
        //handling reading from kernel//

};

class NetlinkProtocol: public ProtocolInterface{

      public:
        NetlinkProtocol();
        virtual void get_socket_d_info() const;
        virtual void get_header_info() const;

};

NetlinkProtocol::NetlinkProtocol(){
    //should define domain type protocol//
}

void NetlinkProtocol::get_socket_d_info() const{
    std::cout << ":) \n" << std::endl;
}

void NetlinkProtocol::get_header_info() const{

}

class PgSocketABS {

    private:
        int sd;
        struct sockaddr;
        ProtocolInterface * pi;
        //buffer

        void interpret_msgs();

    public:
        PgSocketABS(ProtocolInterface * pi);
        ~PgSocketABS();
        void create();
        void bind();
        void subscribe();
        void read();
        void close();
};

PgSocketABS::PgSocketABS(ProtocolInterface * pi){

//     this->create();
//     this->bind();
//     this->subscribe();
     //reading and returning some data to passed buffer ?//
     this->pi = pi;
     //this->create();
}

PgSocketABS::~PgSocketABS(){

}

void PgSocketABS::interpret_msgs(){

}

void PgSocketABS::create(){

      pi->get_socket_d_info();

//    this->sd = socket(domain, type, protocol);
//
//    if ( this->sd < 0 ) {
//        throw -1;
//    }
}

void PgSocketABS::bind(){
    //bind(fd, (struct sockaddr*)&nladdr, sizeof(nladdr));

}

void PgSocketABS::subscribe(){

}

void PgSocketABS::read(){

}

void PgSocketABS::close(){

}



using namespace std;

int main(){
    NetlinkProtocol np = NetlinkProtocol();

    PgSocketABS ns = PgSocketABS(&np);

    cout << sizeof(ns) << typeid(ns).name() << endl;

    ns.close();


}