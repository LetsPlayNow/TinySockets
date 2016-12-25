//
// Created by aleksey on 09.10.16.
//

#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
#include "SocketMessenger.h"
#include <string>

class SocketServer : public SocketMessenger {
public:
    SocketServer(int port);
    ~SocketServer();
    bool AcceptConnection();
    void CloseConnection();

private:
    int server_desc;
    sockaddr_in server;
    sockaddr_in client;
};


#endif //SOCKETSERVER_H