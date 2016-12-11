#include "SocketServer.h"

SocketServer::SocketServer(int port) {
#ifdef _WIN32
    WSADATA wsaData;
    int initResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (initResult != 0) throw MyException("SWA Startup failed");
#endif

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) throw MyException("Could not create socket");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( port );

    //Bind
    bool fail = bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0;
    if (fail) throw MyException("Bind failed");

    listen(socket_desc, 3);
}

SocketServer::~SocketServer() {
#ifdef _WIN32
    closesocket(this->socket_desc);
#elif __linux__
    close(this->socket_desc);
#endif
    
    for (auto it = clients_sockets.cbegin(); it != clients_sockets.cend();){
        CloseConnection(*it++);
    }
}

int SocketServer::AcceptConnection() {
    int new_socket;
    sockaddr_in client;
    int c = sizeof(struct sockaddr_in);
    new_socket = accept(socket_desc, (struct sockaddr *)&client, &c); // (socklen_t*)
    if (new_socket < 0) throw MyException("Accept failed");
    clients_sockets.insert(new_socket);
    return new_socket;
}

void SocketServer::CloseConnection(int socket_desc) {
    clients_sockets.erase(socket_desc);

#ifdef _WIN32
    closesocket(socket_desc);
#elif __linux__
    close(socket_desc);
#endif
}

void SocketServer::Send(int sock_desc, std::string message) {

    bool fail = send(sock_desc, message.c_str(), message.size(), 0) < 0;
    if (fail) throw MyException("Send failed");
}

std::string SocketServer::Recv(int sock_desc) {
    char buffer[2000] = {'\0'};
    bool fail = recv(sock_desc, buffer, 2000, 0) < 0;
    if (fail) throw MyException("Could not receive message");
    return std::string(buffer);
}





