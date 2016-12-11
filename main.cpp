/*
 * Переменные this_var_of_5
 * Функции и публичные методы MyFunction
 * Имена класса MyClass
 * Приватные методы myFunction
 */

#include "SocketClient.h"
#include "SocketServer.h"
#include <iostream>
// Test for client and server
std::string localhost = "127.0.0.1";
int default_port = 50000;

bool shouldSendReceive(){
    SocketServer server(default_port);
    SocketClient client;

    client.Connect(localhost, default_port);
    int client_descr = server.AcceptConnection();

    std::string messageSent = "I am cool!";

    client.Send(messageSent);
    std::string messageRecieved = server.Recv(client_descr);

    client.Disconnect();
    bool success = messageRecieved == messageSent;
    return success;
}

bool shouldCloseConnection(){
    SocketServer server(default_port);
    SocketClient client1; client1.Connect(localhost, default_port);
    int client1_desc = server.AcceptConnection();
    SocketClient client2; client2.Connect(localhost, default_port);
    int client2_desc = server.AcceptConnection();

    const std::string message = "I love this";
    server.Send(client1_desc, message);
    server.Send(client2_desc, message);
    std::string client1_string = client1.Recv();
    std::string client2_string = client2.Recv();

    std::cout << "Client 1 received: " << client1_string << std::endl
              << "Client 2 received: " << client2_string << std::endl;

    client1.Disconnect();
    client2.Disconnect();
    return message == client1_string && message == client2_string;
}


// TODO maybe we should do block stream or use datagram
void sendRecvTest(){
    SocketServer server(default_port);
    SocketClient client;
    client.Connect(localhost, default_port);
    int client_desc = server.AcceptConnection();
    client.Send("Teddy");
    client.Send("Bear");
    std::cout << server.Recv(client_desc);
}

std::string boolToString(bool in){
    return in ? "Success" : "Fail";
}

int main() {
    std::cout << "Should send recv: " << boolToString(shouldSendReceive());
    std::cout << std::endl;
    std::cout << "Should close connections: " << boolToString(shouldCloseConnection());
    sendRecvTest();
    system("pause");
    return 0;
}