//
// Created by aleksey on 15.03.17.
//

#ifndef SOCKETLIB_TCPCLIENT_H
#define SOCKETLIB_TCPCLIENT_H

#include "Client.h"

template <class TemplateConnection>
class TCPClient : public Client<TemplateConnection> {
    TCPClient();
    ~TCPClient();

    TemplateConnection Connect(const std::string ip, const int port);
};

TCPClient::TCPClient()
{

}

TCPClient::~TCPClient()
{

}

template <class TemplateConnection> TemplateConnection TCPClient::Connect(const std::string ip, const int port)
{

    // http://man7.org/linux/man-pages/man2/socket.2.html
    int sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_desc == -1) throw SocketException("[Error] Create socket");

    sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(ip.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // http://man7.org/linux/man-pages/man2/connect.2.html
    bool fail = connect(sock_desc, (struct sockaddr *)&server, sizeof(server)) == -1;
    if (fail) throw SocketException("[Error] Cannot connect to server");

    // todo maybe store it somewhere in TCP client
    return TemplateConnection(sock_desc, server);
}



#endif //SOCKETLIB_TCPCLIENT_H
