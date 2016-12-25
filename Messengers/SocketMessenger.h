#pragma once
#ifdef __linux__
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
#elif _WIN32
    #include <WinSock2.h>
    #include <Windows.h>
    #include <ws2tcpip.h>
#endif

#include "../Messages/Message.h"
#include "../Other/SocketException.h"
#include "../Messages/MessageNum.h"
#include "../Other/Utils.h"
#include <string>

class SocketMessenger
{
public:
    SocketMessenger();

    friend SocketMessenger & operator <<(SocketMessenger & messenger, const MessageNum & message);
    friend SocketMessenger & operator >>(SocketMessenger & messenger, MessageNum & message);

protected:
    void closeSocket(int socket_desc);
    int other_desc;

private:
    void _send(const void * buffer, size_t size);
    void _recv(void * buffer, size_t size);
};