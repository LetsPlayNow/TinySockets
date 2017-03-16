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
        sockaddr_in server;
        sockaddr_in client;

        // Create socket
        int sock_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        bool socket_fail = sock_desc == -1;
        if (socket_fail) throw SocketException("[UDPServer::UDPServer()] Can't create socket");

        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = htonl(INADDR_ANY);

        bool bind_fail = bind(sock_desc, (sockaddr*)&server, sizeof(server)) == -1;
        if (bind_fail) throw SocketException("[UDPServer::UDPServer()] Can't bind socket");
    }

    ~UDPServer()
    {

    }

    TemplateConnection AcceptConnection()
    {

    }
};

// fixme we cannot send here using send, recv.
// fixme only sendto, recvfrom

#endif //SOCKETLIB_UDPSERVER_H
