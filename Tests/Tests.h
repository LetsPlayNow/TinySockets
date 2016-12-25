#pragma once
#include "../Messengers/SocketClient.h"
#include "../Messengers/SocketServer.h"
#include <iostream>
#include <string>
#include "../Messages/MessageNum.h"
#include "../Other/Utils.h"

// Module contains some simple tests 
// and function of simple Server reciever, Client sender
namespace Test {
    using namespace std;

    extern string localhost;
    extern int default_port;

    bool shouldSendReceive();
    bool shouldRecvFirst();
    bool shouldNotRecvAfterClientTermination();
  
    void RunAlltests();

    // Need separate executables (Client.cpp, Server.cpp)
    void ServerTest();
    void ClientTest();
}
