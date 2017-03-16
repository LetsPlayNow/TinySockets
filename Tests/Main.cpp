#include "Tests.h"
#include <iostream>

int main()
{
    Test::UdpSendRecvTest();
    Test::TcpSendRecvTest();
    std::cout << "Tests successfully completed";
    return 0;
}

// todo add perror outputs near of erors checks. They are very good
// try using this method http://man7.org/linux/man-pages/man3/strerror.3.html