#include <iostream>
#include "pg_socket/PgSocketNetlinkClass.hpp"



int main(){

    PgSocketNetlinkClass s = PgSocketNetlinkClass(1, 1, 2);

    std::cout << "HELLO!" << std::endl;
}