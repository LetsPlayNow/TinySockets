#include "Tests.h"
#include <iostream>

int main()
{
    std::cout << "UDP test: ";
    Test::UdpSendRecvTest();
    std::cout << "Success" << std::endl;
    std::cout << "TCP test: ";
    Test::TcpSendRecvTest();
    std::cout << "Success" << std::endl;
    std::cout << "All tests successfully completed";
    return 0;
}