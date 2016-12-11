#include "SocketServer.h"

SocketServer::SocketServer(int port) : SocketMessenger() {
#ifdef _WIN32
    WSADATA wsaData;
    int initResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (initResult != 0) throw SocketException("[Error] SWA Startup");
#endif

    //Create socket
    server_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (server_desc == -1) throw SocketException("[Error] Create socket");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( port );

    //Bind
    bool fail = bind(server_desc, (struct sockaddr *)&server , sizeof(server)) < 0;
    if (fail) throw SocketException("[Error] Bind socket");

    listen(server_desc, 3);
}

void SocketServer::AcceptConnection() {
    int c = sizeof(struct sockaddr_in);
    other_desc = accept(server_desc, (struct sockaddr *)&client, &c); // (socklen_t*)
    if (other_desc < 0) throw SocketException("[Error] Accept connection");
}

void SocketServer::CloseConnection()
{
    closeSocket(other_desc);
    other_desc = -1;
}

SocketServer::~SocketServer() {
    closeSocket(server_desc);
    closeSocket(other_desc);

#ifdef _WIN32
    WSACleanup();
#endif
}





