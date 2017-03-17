#ifndef SOCKETLIB_TCPCLIENT_H
#define SOCKETLIB_TCPCLIENT_H

#include "Client.h"

template <class TemplateConnection>
class TCPClient : public Client<TemplateConnection> {
public:
    TemplateConnection Connect(const std::string ip, const int port)
    {
        TCPClientSocket socket(ip, port);
        sockaddr_in other = socket.GetDestinationAddress(); // fixme ugly call
        bool connect_fail = connect(socket.GetDescriptor(), (sockaddr *)& other, sizeof(other)) == -1;
        if (connect_fail) throw SocketException("[TCPClient::TCPClient()] connect() fail");

        return TemplateConnection(&socket);
    }
};


#endif //SOCKETLIB_TCPCLIENT_H
