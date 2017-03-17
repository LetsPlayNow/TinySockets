#include "Tests.h"
#include <iostream>

int main()
{
    Test::UdpSendRecvTest();
    Test::TcpSendRecvTest();
    std::cout << "Tests successfully completed";
    return 0;
}