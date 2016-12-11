#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H
#include "SocketMessenger.h"
#include <string>

class SocketClient : public SocketMessenger {
public:
    SocketClient();
    ~SocketClient();
    void Connect(std::string address, int port);
    void Disconnect();

private:
    sockaddr_in server;
};


#endif //SOCKETCLIENT_H