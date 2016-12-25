#include "SocketMessenger.h"
#include <iostream>

SocketMessenger::SocketMessenger()
{
    other_desc = -1;
}

void SocketMessenger::closeSocket(int socket_desc) {
    if (socket_desc == -1)
        return;
    closesocket(socket_desc);
}

SocketMessenger &operator<<(SocketMessenger &messenger, const MessageNum &message) {

    messenger._send(&message.number, sizeof(int));
    return messenger;
}

SocketMessenger &operator>>(SocketMessenger &messenger, MessageNum &message) {
    messenger._recv(&message.number, sizeof(int));
    return messenger;
}

void SocketMessenger::_send(const void *buffer, size_t size) {
    bool fail = send(other_desc, (char*)buffer, size, 0) <= 0;
    if (fail) throw SocketException("[Error] Can't send message");
}

void SocketMessenger::_recv(void *buffer, size_t size) {
    int fail = recv(other_desc, (char*)buffer, size, 0) <= 0;
    if (fail) throw SocketException("[Error] Can't recv message");
}








