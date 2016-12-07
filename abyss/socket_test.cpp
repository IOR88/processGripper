/**

@@@META@@@

Nodes (CPCs or FECs as illustrated above) connect to the wire and
register to receive specific messages.  CPCs may connect to multiple
wires if it helps them to control the service better.  All nodes
(CPCs and FECs) dump packets on the broadcast wire.  Packets can be
discarded by the wire if they are malformed or not specifically
formatted for the wire.  Dropped packets are not seen by any of the
nodes.  The Netlink service may signal an error to the sender if it
detects a malformatted Netlink packet.

Packets sent on the wire can be broadcast, multicast, or unicast.
FECs or CPCs register for specific messages of interest for
processing or just monitoring purposes.

**/


#include <sys/socket.h>
#include <linux/netlink.h>
#include <iostream>
#include <typeinfo>
//class

struct sockinit {
    int domain;
    int type;
    int protocol;
};



class ProtocolInterface {

    public:
        //pure virtual functions, classes which inherit must to implement those functions//
        virtual sockinit get_sockinit() const = 0;
        virtual sockaddr get_sockaddr() const = 0;
        //initialization_msg//
        //handling reading from kernel//

};

//general on http://opensourceforu.com/2015/08/netlink-a-communication-mechanism-in-linux///


class NetlinkMessageClass {
    //https://tools.ietf.org/html/rfc3549

    //There are three levels to a Netlink message: The general Netlink
    //message header, the IP service specific template, and the IP service
    //specific data.

    //The Netlink message header is generic for all services, whereas the
    //IP Service Template header is specific to a service.  Each IP Service
    //then carries parameterization data (CPC->FEC direction) or response
    //(FEC->CPC direction).  These parameterizations are in TLV (Type-
    //Length-Value) format and are unique to the service.

    private:
        struct nlmsghdr header;

    public:
        void set_netlink_hdr(
            __u32 nlmsg_len,
            __u16 nlmsg_type,
            __u16 nlmsg_flags,
            __u32 nlmsg_seq,
            __u32 nlmsg_pid);
        struct nlmsghdr get_netlink_hdr();

    //    struct nlmsghdr
    //        {
    //          __u32 nlmsg_len;   /* Length of message */
    //          __u16 nlmsg_type;  /* Message type*/
    //          __u16 nlmsg_flags; /* Additional flags */
    //          __u32 nlmsg_seq;   /* Sequence number */
    //          __u32 nlmsg_pid;   /* Sending process PID */
    //        };



};



class NetlinkProtocol: public ProtocolInterface{

      private:
        struct sockinit socket_structure;

      public:
        NetlinkProtocol();
        virtual sockinit get_sockinit() const;
        virtual sockaddr get_sockaddr() const;

};

NetlinkProtocol::NetlinkProtocol(){

    this->socket_s = {AF_NETLINK, SOCK_DGRAM, NETLINK_ROUTE};
}

socket_s NetlinkProtocol::get_sockinit() const{
    ///return this->socket_s;
}

sockaddr NetlinkProtocol::get_sockaddr() const{

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
        void subscribe();//register
        void read();
        void close();
};

PgSocketABS::PgSocketABS(ProtocolInterface * pi){
     this->pi = pi;
}

PgSocketABS::~PgSocketABS(){

}

void PgSocketABS::interpret_msgs(){

}

void PgSocketABS::create(){

    sockinit si = pi->get_socket_s_info();

    this->sd = socket(si.domain, si.type, si.protocol);

    if ( this->sd < 0 ) {
        throw -1;
    }
}

void PgSocketABS::bind(){
    //the netlink bind() API associates a local (source) socket address with the opened socket
    //bind(fd, (struct sockaddr*)&nladdr, sizeof(nladdr));
    sockaddr sa = pi->get

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