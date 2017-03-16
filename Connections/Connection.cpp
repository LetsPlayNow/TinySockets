//
// Created by aleksey on 15.03.17.
//

#include "Connection.h"

Connection::Connection()
{
    _sock_desc = -1;
}

Connection::Connection(int sock_desc, sockaddr_in other)
{
    _sock_desc = sock_desc;
    _other = other;
}

Connection::~Connection()
{
    close(_sock_desc);
}

int Connection::GetDescriptor()
{
    return _sock_desc;
}

void Connection::_send(const void *buffer, size_t size)
{
    bool fail = send(_sock_desc, (char*)buffer, size, 0) <= 0;
    if (fail) throw SocketException("[Error] Can't send message");
}

void Connection::_recv(void *buffer, size_t size)
{
    bool fail = recv(_sock_desc, (char*)buffer, size, 0) <= 0;
    if (fail) throw SocketException("[Error] Can't recv message");
}

Connection & operator <<(Connection & connection, const int number)
{
    connection._send(&number, sizeof(int));
    return connection;
}

Connection & operator >>(Connection & connection, int & number)
{
    connection._recv(&number, sizeof(int));
    return connection;
}






