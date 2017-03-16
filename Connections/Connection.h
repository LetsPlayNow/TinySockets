#ifndef SOCKETLIB_CONNECTION_H
#define SOCKETLIB_CONNECTION_H

#include "Socket.h"
// If you want to add your message support, just inherit from this class and add your own >> << methods

class Connection {
public:
    Connection()
    { _socket = new Socket(); }

    Connection(const Socket * socket)
    {
        _socket = new Socket();
        *_socket = *socket; // fixme there can be memory leak. (can it work without memory allocation?)
    }

    ~Connection()
    { delete _socket; }

    Socket GetSocket()
    { return *_socket; }

    friend Connection & operator <<(Connection & connection, const int number)
    {
        connection._socket->Send(&number, sizeof(int));
        return connection;
    }

    friend Connection & operator >>(Connection & connection, int & number)
    {
        connection._socket->Recv(&number, sizeof(int));
        return connection;
    }

protected:
    Socket * _socket;
};

#endif //SOCKETLIB_CONNECTION_H
