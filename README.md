# TinySockets
**Tiny object oriented header only sockets library
It supports UDP and TCP**

![](https://habrastorage.org/files/858/6a0/e83/8586a0e83c0c49d6936f2c0b2785c2ac.png)

## Project Structure
### Connections
There are Socket and Connection classes.
You can inherit from Connection class and override << and >> operators for every thing you want.
Socket classes are not for direct use.
###Communicators
There are TCP and UDP client and server template classes.
You can use them with tour own Connection class.
### Utils
There are SocketException class
### Tests
Tests for Communicators
Now there are only Send/Recv tests


## Main Classes description
### Connection
Just inherit from Connection class and implement methods '>>' '<<' for your struct or class
![](https://habrastorage.org/files/619/2dc/2b4/6192dc2b4731432daf15a04ed318997d.png)
Then just use this class as type in TCP/UDP/Client/Server templates.

Server and client returns Connection object, when connection established
(methods `AcceptConnection()` for Server classes and `Connect()` for Client classes)


### Clients and servers
Every Client has
`TemplateConnection Connect(const std::string ip, const int port)`

Every Server class has
` TemplateConnection AcceptConnection()`

### TCPServer
It binds one socket and listens connections via it.
When new connections comes, it opens new socket via `accept()`
and creates new connection with client.

### TCPClient
It does not need to bind it's own address to socket.
It's just calls `connect()` method with server address.

### UDPServer
It binds it's own port and awaits for request via `recvfrom()`.
In `recvfrom()` it make explictly bind to incoming connection.


### UDPClient
It just calling `sendto()` with address of server.


