#ifndef SOCKETLIB_SOCKET_H
#define SOCKETLIB_SOCKET_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "../Other/SocketException.h" // todo fix this relation path with cmake

class Socket
{
public:
    Socket()
    {
        _sock_desc = -1;
    }
    ~Socket()
    {
        // fixme if socket goes out of vision area, it automatically closes. but I have many socket copy - paste
        // fixme maybe server should have list of connections and close them itself
        // close(_sock_desc);
    }

    // Note sedndto and recvfrom works for both types of connections
    void Send(const void * buffer, size_t size)
    {
        int status = sendto(_sock_desc, buffer, size, 0, (sockaddr *)&_other, sizeof(_other));
        bool send_fail = status == -1;
        if (send_fail) throw SocketException("[Socket::Send()] sendto() failed");
    }

    int Recv(void * buffer, size_t size)
    {
        int addr_len;
        int received = recvfrom(_sock_desc, buffer, size, 0, (sockaddr *)&_other, (socklen_t *)&addr_len);
        bool recv_fail = received == -1;
        bool no_messages = received == 0;
        if (recv_fail || no_messages) throw SocketException("[Socket::Recv()] recvfrom() failed");
        return received;
    }

    int GetDescriptor() { return _sock_desc; }
    sockaddr_in GetDestinationAddress() { return _other; }
    sockaddr_in GetMyAddress() { return _my_addr; }
protected:
    int _sock_desc;
    sockaddr_in _other;
    sockaddr_in _my_addr;
};

// TCP sockets
class TCPSocket : public Socket
{ };

class TCPServerListenSocket : public TCPSocket
{
public:
    TCPServerListenSocket(int port)
    {
        // http://man7.org/linux/man-pages/man2/socket.2.html
        _sock_desc = socket(AF_INET, SOCK_STREAM, 0);
        if (_sock_desc == -1) throw SocketException("[Error] Create socket");

        _my_addr.sin_family = AF_INET;
        _my_addr.sin_addr.s_addr = INADDR_ANY;
        _my_addr.sin_port = htons( port );
    }
};

class TCPClientSocket : public TCPSocket
{
public:
    TCPClientSocket(std::string ip, int port)
    {
        // http://man7.org/linux/man-pages/man2/socket.2.html
        _sock_desc = socket(AF_INET, SOCK_STREAM, 0);
        if (_sock_desc == -1) throw SocketException("[Error] Create socket");

        _other.sin_family = AF_INET;
        _other.sin_port = htons( port );
        _other.sin_addr.s_addr = inet_addr(ip.c_str());
    }

    TCPClientSocket(int sock_desc, sockaddr_in other)
    {
        _sock_desc = sock_desc;
        _other = other;
    }
};

// UDP sockets
class UDPSocket : public Socket
{};

class UDPServerSocket : public UDPSocket
{
public:
    // Server don't need to know ip address of client
    UDPServerSocket(int port)
    {
        _sock_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        bool socket_fail = _sock_desc == -1;
        if (socket_fail) throw SocketException("[UDPServer::UDPServer()] Can't create socket");

        // Preset my address
        _my_addr.sin_family = AF_INET;
        _my_addr.sin_port = htons(port);
        _my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

        bool bind_fail = bind(_sock_desc, (sockaddr*)&_my_addr, sizeof(_my_addr)) == -1;
        if (bind_fail) throw SocketException("[UDPServer::UDPServer()] Can't bind socket");
    }
};

class UDPClientSocket : public Socket
{
public:
    // Client don't need to preset it's own address
    UDPClientSocket(std::string ip, int port)
    {
        _sock_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        bool socket_fail = _sock_desc == -1;
        if (socket_fail) throw SocketException("[UDPServer::UDPServer()] Can't create socket");

        _other.sin_family = AF_INET;
        _other.sin_port = htons(port);
        _other.sin_addr.s_addr = inet_addr(ip.c_str());
    }
};


#endif //SOCKETLIB_SOCKET_H
