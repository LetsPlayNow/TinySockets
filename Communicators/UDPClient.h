//
// Created by aleksey on 15.03.17.
//

#ifndef SOCKETLIB_UDPCLIENT_H
#define SOCKETLIB_UDPCLIENT_H

#include "Client.h"

template <class TemplateConnection>
class UDPClient : public Client<TemplateConnection>{
    TemplateConnection Connect(const std::string ip, const int port)
    {
        UDPSocket sock(port, ip);
        return TemplateConnection(&sock);
    }
};


#endif //SOCKETLIB_UDPCLIENT_H
