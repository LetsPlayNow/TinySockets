//
// Created by aleksey on 15.03.17.
//

#ifndef SOCKETLIB_TCPCLIENT_H
#define SOCKETLIB_TCPCLIENT_H

#include "Client.h"

template <class TemplateConnection>
class TCPClient : public Client<TemplateConnection> {
public:
    TemplateConnection Connect(const std::string ip, const int port)
    {
        TCPSocket socket(ip, port);
        return TemplateConnection(socket);
    }
};


#endif //SOCKETLIB_TCPCLIENT_H
