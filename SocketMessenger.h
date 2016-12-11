#pragma once
#include "Message.h"
#include "SocketException.h"
#ifdef __linux__
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#elif _WIN32
#include <WinSock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#endif

class SocketMessenger
{
public:
    SocketMessenger();
    virtual ~SocketMessenger();

    // Interface to send simple structs
    friend SocketMessenger & operator <<(SocketMessenger & messenger, const Message & message);
    friend SocketMessenger & operator >>(SocketMessenger & messenger, Message & message);

protected:
    int other_desc;
};

