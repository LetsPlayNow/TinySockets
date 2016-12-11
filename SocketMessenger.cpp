#include "SocketMessenger.h"


SocketMessenger::SocketMessenger()
{
}


SocketMessenger::~SocketMessenger()
{
}

SocketMessenger & operator <<(SocketMessenger & messenger, const Message & message) {
    int message_size = sizeof(message);
    bool fail = send(messenger.other_desc, (char *)&message_size, sizeof(int), 0) < 0;
    if (fail) throw SocketException("[Send] Can't send size of Message");

    bool fail = send(messenger.other_desc, (char *)&message, message_size, 0) < 0;
    if (fail) throw SocketException("[Send] Can't send Message");

    return messenger;
}

SocketMessenger & operator >>(SocketMessenger & messenger, Message & message) {
    int message_size;
    bool fail = recv(messenger.other_desc, (char *)&message_size, sizeof(int), 0) < 0;
    if (fail) throw SocketException("[Recv] Can't recv size of Message");

    bool fail = recv(messenger.other_desc, (char *)&message, message_size, 0) < 0;
    if (fail) throw SocketException("[Recv] Can't recv Message");

    return messenger;
}
