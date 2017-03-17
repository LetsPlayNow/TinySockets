#ifndef SOCKETLIB_UDPCLIENT_H
#define SOCKETLIB_UDPCLIENT_H

#include "Client.h"

template <class TemplateConnection>
class UDPClient : public Client<TemplateConnection>{
public:
    TemplateConnection Connect(const std::string ip, const int port)
    {
        UDPClientSocket socket(ip, port);
        return TemplateConnection(&socket);
    }
};


#endif //SOCKETLIB_UDPCLIENT_H
