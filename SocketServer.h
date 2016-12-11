//
// Created by aleksey on 09.10.16.
//

#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
#ifdef __linux__
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
#elif _WIN32
    #include <WinSock2.h>
    #include <Windows.h>
    #include <ws2tcpip.h>
#endif

#include <string>
#include <set>
#include "MyException.h"

class SocketServer {
public:
    SocketServer(int port);
    ~SocketServer();
    int AcceptConnection();
    void CloseConnection(int socket_desc);

    void Send(int sock_desc, std::string message);
    std::string Recv(int sock_desc);
private:
    int socket_desc;
    std::set<int> clients_sockets;
    sockaddr_in server;
};


#endif //SOCKETSERVER_H