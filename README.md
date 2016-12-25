# TinySockets
Tiny cross-platform sockets peer to peer library.  
This project was tested on Ubuntu with Clion and on Windows 10 with Visual Studio.

## Project Structure
### Debug
It's debug folder for Visual Studio
### Messages
Folder for Messages classes
### Messengers
Folder for Messengers classes (Client, Server)
### Other
Some help staff, like library's own exception class and define header for ubuntu
### Tests
* Tests class with small simple tests for sockets
* Client - Server tests (Client.cpp, Server.cpp)  
In this tests client sends to Server simple message with number inside

## Main Classes description
### Socket Messenger
It's an abstract class with send/recv methods  
If you want to add send/recv for your class, override << and >> ooperators for them  
Also contains descriptor of socket to write/read from it.

### SocketClient
Child of Socket Messenger  
Has some specific methods:
* TryConnect (try connect 1 time)
* Connect (try connect many times with delay)
* Disconnect

### SocketServer
Child of Socket Messenger  
Has some specific methods:
* TryAcceptConnection (try connect 1 time)
* AcceptConnection (try connect many times with delay)
* CloseConnection
