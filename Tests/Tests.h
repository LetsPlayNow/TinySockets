#pragma once
#include "../Communicators/TCPClient.h"
#include "../Communicators/TCPServer.h"
#include "../Communicators/UDPClient.h"
#include "../Communicators/UDPServer.h"
#include "../Connections/Connection.h"
#include <iostream>
#include <string>
#include <assert.h>

namespace Test
{
    extern std::string default_ip;
    extern int default_port;

    void TcpSendRecvTest();
    void UdpSendRecvTest();
}