#pragma once
#include "../Communicators/TCPClient.h"
#include "../Communicators/TCPServer.h"
#include "../Communicators/UDPClient.h"
#include "../Communicators/UDPServer.h"
#include "../Connections/Connection.h"
#include <iostream>
#include <string>

namespace Test
{
    using namespace std;
    string localhost = "127.0.0.1";
    int default_port = 50000;

    bool TcpSendRecvTest();
    bool UdpSendRecvTest();
}