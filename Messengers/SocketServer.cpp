#include "SocketServer.h"

SocketServer::SocketServer(int port) : SocketMessenger() 
{
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
    bool fail = bind(server_desc, (struct sockaddr *)&server , sizeof(server)) == -1;
    if (fail) throw SocketException("[Error] Bind socket");

    listen(server_desc, 3);
}

bool SocketServer::TryAcceptConnection() 
{
    socklen_t c = sizeof(client);
    other_desc = accept(server_desc, (struct sockaddr *)&client, &c);
    return other_desc != -1;
}

void SocketServer::AcceptConnection(int retries_limit, int delayms) 
{
    int retries_count = 0;
    while (!TryAcceptConnection() && retries_count < retries_limit)
    {
        Sleep(delayms);
        retries_count++;
    }
}

void SocketServer::CloseConnection()
{
    closeSocket(other_desc);
    other_desc = -1;
}

SocketServer::~SocketServer()
{
    closeSocket(server_desc);
    closeSocket(other_desc);

#ifdef _WIN32
    WSACleanup();
#endif
}





