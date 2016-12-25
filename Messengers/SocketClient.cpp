#include "SocketClient.h"

SocketClient::SocketClient() : SocketMessenger() {
#ifdef _WIN32
    WSADATA wsaData;
    int initResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (initResult != 0) throw SocketException("[Error] SWA Startup");
#endif
}


bool SocketClient::Connect(std::string address, int port) {
    // http://man7.org/linux/man-pages/man2/socket.2.html
    other_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (other_desc == -1) throw SocketException("[Error] Create socket");

    server.sin_addr.s_addr = inet_addr(address.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // http://man7.org/linux/man-pages/man2/connect.2.html
    bool fail = connect(other_desc, (struct sockaddr *)&server, sizeof(server)) == -1;
    return !fail;
}


void SocketClient::Disconnect() {
    closeSocket(other_desc); 
    other_desc = -1;
}


SocketClient::~SocketClient() {
    Disconnect();
#ifdef _WIN32
    WSACleanup();
#endif
}








