#ifndef SOCKETLIB_TCPSERVER_H
#define SOCKETLIB_TCPSERVER_H

#include "Server.h"

template <class TemplateConnection>
class TCPServer : Server<TemplateConnection>
{
public:
    TCPServer(int port, int queue_length = 3) : listener(port)
    {
        sockaddr_in my_addr = listener.GetMyAddress();
        int sock_desc = listener.GetDescriptor();
        bool fail = bind(sock_desc, (struct sockaddr *)&my_addr, sizeof(my_addr)) == -1;
        if (fail) throw SocketException("[TCPServer::TCPServer()] bind() failed");

        listen(sock_desc, queue_length);
    }

    TemplateConnection AcceptConnection()
    {
        sockaddr_in client;
        socklen_t c = sizeof(client);
        int client_desc = accept(listener.GetDescriptor(), (struct sockaddr *)&client, &c);
        bool fail = client_desc == -1;
        // todo good naming idea (namespaces)
        if (fail) throw SocketException("[TCP::Server::AcceptConnection] Can't accept connection");

        TCPClientSocket client_socket(client_desc, client);
        return TemplateConnection(&client_socket);
    }

private:
    TCPServerListenSocket listener; // todo maybe make it a connection
};


#endif //SOCKETLIB_TCPSERVER_H
