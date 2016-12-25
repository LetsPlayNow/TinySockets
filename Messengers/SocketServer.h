//
// Created by aleksey on 09.10.16.
//

#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
#include "SocketMessenger.h"
#include <string>
#include "../Other/Utils.h"

class SocketServer : public SocketMessenger {
public:
    SocketServer(int port);
    ~SocketServer();
    bool TryAcceptConnection();
    void AcceptConnection(int retries_limit = 10, int delayms=1000);
    void CloseConnection();

private:
    int server_desc;
    sockaddr_in server;
    sockaddr_in client;
};


#endif //SOCKETSERVER_H