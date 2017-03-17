#ifndef SOCKETLIB_UDPSERVER_H
#define SOCKETLIB_UDPSERVER_H

#include "Server.h"

template <class TemplateConnection>
class UDPServer : Server<TemplateConnection>
{
public:
    UDPServer(int port)
    {
        _server_port = port;
    }

    TemplateConnection AcceptConnection()
    {
        UDPServerSocket socket(_server_port); // we will figure out user address after recvfrom
        return TemplateConnection(&socket);
    }

private:
    int _server_port;
};

#endif //SOCKETLIB_UDPSERVER_H
