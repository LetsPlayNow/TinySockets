//
// Created by aleksey on 15.03.17.
//

#ifndef SOCKETLIB_UDPSERVER_H
#define SOCKETLIB_UDPSERVER_H

#include "Server.h"


template <class TemplateConnection>
class UDPServer : Server<TemplateConnection>{
    UDPServer(int port)
    {
        _server_port = port;
    }
    TemplateConnection AcceptConnection()
    {
        UDPSocket sock(_server_port); // we will figure out user address after recvfrom
        return TemplateConnection(&sock);
    }

private:
    int _server_port;
};

#endif //SOCKETLIB_UDPSERVER_H
