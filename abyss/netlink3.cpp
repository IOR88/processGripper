#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/netlink.h>
#include <iostream>
#include <cerrno>



//http://inai.de/documents/Netlink_Protocol.pdf
int main()
{
    ssize_t ret;
    char buf[]= "Hello world";


    struct sockaddr_nl dst;

    dst.nl_family = AF_NETLINK;
    dst.nl_pid = getpid();

    int sk = socket(AF_NETLINK, SOCK_RAW, 0);
    if(sendto(sk, buf, strlen(buf), 0,
        (const sockaddr *)&dst,
        sizeof
        (dst)) < 0) {
            perror("sendto");
            abort();
        }

    ret = recv(sk, buf,sizeof(buf), 0);
    if(ret < 0) {
        perror("recv");
        abort();
    }

    std::cout << ret << "  " << errno << std::endl;

    printf("%.*s\n", (int)ret, buf);
    return EXIT_SUCCESS;
}