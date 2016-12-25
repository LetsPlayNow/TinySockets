#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H
#include "SocketMessenger.h"
#include <string>
#include "../Other/Utils.h"

class SocketClient : public SocketMessenger {
public:
    SocketClient();
    ~SocketClient();
    bool TryConnect(std::string address, int port);
    void Connect(std::string address, int port, int retries_limit = 10, int delayms = 1000);
    void Disconnect();

private:
    sockaddr_in server;
};


#endif //SOCKETCLIENT_H