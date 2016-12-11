#include "SocketMessenger.h"


SocketMessenger::SocketMessenger()
{
    other_desc = -1;
}

void SocketMessenger::closeSocket(int socket_desc)
{
    if (socket_desc == -1)
        return;

#ifdef _WIN32
    closesocket(socket_desc);
#elif __linux__
    close(socket_desc);
#endif
}

SocketMessenger & operator <<(SocketMessenger & messenger, const Message & message) {
    int message_size = sizeof(message);
    bool fail = send(messenger.other_desc, (char *)&message_size, sizeof(int), 0) < 0;
    if (fail) throw SocketException("[Error] Can't Send size of Message");

    fail = send(messenger.other_desc, (char *)&message, message_size, 0) < 0;
    if (fail) throw SocketException("[Error] Can't Send Message");

    return messenger;
}

SocketMessenger & operator >>(SocketMessenger & messenger, Message & message) {
    int message_size;
    bool fail = recv(messenger.other_desc, (char *)&message_size, sizeof(int), 0) < 0;
    if (fail) throw SocketException("[Error] Can't Recv size of Message");

    fail = recv(messenger.other_desc, (char *)&message, message_size, 0) < 0;
    if (fail) throw SocketException("[Error] Can't Recv Message");

    return messenger;
}
