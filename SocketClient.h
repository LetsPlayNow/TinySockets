//
// Created by aleksey on 09.10.16.
//

#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H
#ifdef __linux__
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
#elif _WIN32
    #include <WinSock2.h>
    #include <Windows.h> 
    #include <ws2tcpip.h>
#endif

#include "MyException.h"
#include <string>

class SocketClient {
public:
    SocketClient();
    ~SocketClient();
    void Connect(std::string address, int port);
    void Disconnect();

    void Send(std::string message);
    std::string Recv();

private:
    sockaddr_in server;
    int socket_desc;
};


#endif //SOCKETCLIENT_H