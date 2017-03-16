//
// Created by aleksey on 15.03.17.
//
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "../Other/SocketException.h" // todo fix this relation path with cmake

#ifndef SOCKETLIB_CONNECTION_H
#define SOCKETLIB_CONNECTION_H

// If you want to add your message support, just inherit from this class and add your own >> << methods
// fixme we can do two class TCP Connection and UDP connection or use one class with if else
class Connection {
public:
    Connection();
    Connection(int sock_desc, sockaddr_in other);
    ~Connection();

    int GetDescriptor();

    // TODO operators >> << for many common types here
    // maybe close connection operator here?
    friend Connection & operator <<(Connection & connection, const int number);
    friend Connection & operator >>(Connection & connection, int & number);

private:
    void _send(const void * buffer, size_t size);
    void _recv(void * buffer, size_t size);

protected:
    int _sock_desc;
    sockaddr_in _other;
};


#endif //SOCKETLIB_CONNECTION_H
