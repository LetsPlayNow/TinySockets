#pragma once
#include "SocketClient.h"
#include "SocketServer.h"
#include <iostream>
#include <string>

// Module contains some simple tests and function of simple Server reciever, Client sender
namespace Test {
    std::string localhost = "127.0.0.1";
    int default_port = 50000;

    struct MessageNum : Message {
        MessageNum(int num = 10) : number(num) {}
        int number;
    };

    bool shouldSendReceive() {
        SocketServer server(default_port);
        SocketClient client;

        client.Connect(localhost, default_port);
        server.AcceptConnection();

        MessageNum messageSent(15);
        client << messageSent;

        MessageNum messageRecv;
        server >> messageRecv;

        client.Disconnect();
        bool success = messageRecv.number == messageSent.number;
        return success;
    }

    // TODO maybe we should do block stream or use datagram
    bool shouldRecvFirst() {
        SocketServer server(default_port);
        SocketClient client;
        client.Connect(localhost, default_port);
        server.AcceptConnection();

        client << MessageNum(10);
        client << MessageNum(15);

        MessageNum recieved;
        server >> recieved;

        return recieved.number == 10;
    }

    std::string boolToString(bool in) {
        return in ? "Success" : "Fail";
    }

    void RunAlltests() {
        std::cout << "Should send recv: " << boolToString(shouldSendReceive()) << std::endl;
        std::cout << "Should recieve first message: " << boolToString(shouldRecvFirst()) << std::endl;
    }

    void ServerTest() {
        Test::MessageNum message;

        while(true){
            try{
                SocketServer server(50000);
                server.AcceptConnection();

                server >> message;
                std::cout << message.number << std::endl;
            }
            catch(SocketException exception){
                std::cout << exception.what();
                return;
            }
        }
    }

    void ClientTest() {
        Test::MessageNum message;
        std::string address;
        //std::cin >> address;
        while(true){
            try {
                SocketClient client;
                client.Connect("172.16.7.44", 50000);

                std::cin >> message.number;
                client << message;
            }
            catch(SocketException exception){
                std::cout << exception.what();
                return;
            }
        }
    }
}
