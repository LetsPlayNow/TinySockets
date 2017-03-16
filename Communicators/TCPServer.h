//
// Created by aleksey on 15.03.17.
//

#ifndef SOCKETLIB_TCPSERVER_H
#define SOCKETLIB_TCPSERVER_H


#include "Server.h"
template <class TemplateConnection>
class TCPServer : Server<TemplateConnection>{
    TCPServer(int port, int queue_length = 3)
    {
        //Create socket
        int server_desc = socket(AF_INET , SOCK_STREAM , 0);
        if (server_desc == -1) throw SocketException("[Error] Create socket");

        //Prepare the sockaddr_in structure
        sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons( port );

        //Bind to myself
        bool fail = bind(server_desc, (struct sockaddr *)&server , sizeof(server)) == -1;
        if (fail) throw SocketException("[Error] Bind socket");

        listen(server_desc, queue_length);
        listener = Connection(server_desc, server);
    }
    ~TCPServer()
    {

    }

    TemplateConnection AcceptConnection()
    {
        sockaddr_in client;
        socklen_t c = sizeof(client);
        int client_desc = accept(listener.GetDescriptor(), (struct sockaddr *)&client, &c);
        bool fail = client_desc == -1; // todo check real codes of errors
        // todo good idea for namespaces and error messages
        if (fail) throw SocketException("[TCP::Server::AcceptConnection] Can't accept connection");
        return TemplateConnection(client_desc, client);
    }

private:
    Connection listener;
};


#endif //SOCKETLIB_TCPSERVER_H
