#include "SocketClient.h"

void SocketClient::Send(std::string message) {

    bool fail = send(socket_desc, message.c_str(), message.size(), 0) < 0;
    if (fail) throw MyException("Send failed");
}

std::string SocketClient::Recv() {
    char buffer[2000] = {'\0'};
    bool fail = recv(socket_desc, buffer, 2000, 0) < 0;
    if (fail) throw MyException("Could not receive message");
    return std::string(buffer);
}

void SocketClient::Connect(std::string address, int port) {
    // http://man7.org/linux/man-pages/man2/socket.2.html
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) throw MyException("Could not create socket");

    server.sin_addr.s_addr = inet_addr(address.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // http://man7.org/linux/man-pages/man2/connect.2.html
    bool fail = connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0;
    if (fail) throw MyException("Could not connect");
}


void SocketClient::Disconnect() {
#ifdef _WIN32
    closesocket(socket_desc);
#elif __linux__
    close(socket_desc);
#endif
    
    socket_desc = -1;
}

SocketClient::SocketClient() {
#ifdef _WIN32
    WSADATA wsaData;
    int initResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (initResult != 0) throw MyException("SWA Startup failed");
#endif

    socket_desc = -1;
}


SocketClient::~SocketClient() {
    if (socket_desc != -1){
        Disconnect();
    }

    WSACleanup();
}








