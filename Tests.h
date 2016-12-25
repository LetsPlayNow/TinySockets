#pragma once
#include "SocketClient.h"
#include "SocketServer.h"
#include <iostream>
#include <string>
#include "MessageNum.h"

// Module contains some simple tests and function of simple Server reciever, Client sender
namespace Test {
    using namespace std;

    string localhost = "127.0.0.1";
    int default_port = 45000;

    bool shouldSendReceive() {
        SocketServer server(default_port);
        SocketClient client;

        client.Connect(localhost, default_port);
        server.AcceptConnection();

        MessageNum messageSent(13);
        client << messageSent;

        MessageNum messageRecv;
        server >> messageRecv;

        client.Disconnect();
        bool success = messageRecv.number == messageSent.number;
        return success;
    }

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

    string boolToString(bool in) {
        return in ? "Success" : "Fail";
    }

    void RunAlltests() {
        cout << "Should send recv: " << boolToString(shouldSendReceive()) << endl;
        cout << "Should recieve first message: " << boolToString(shouldRecvFirst()) << endl;
    }


    void ServerTest()
    {
        SocketServer server(default_port);

        // Connection
        bool isConnected;
        do
        {
            isConnected = server.AcceptConnection();
            sleep(1);
        }while(!isConnected);
        cout << "Client connected" << endl;

        // Data transfer
        while(true)
        {
            MessageNum message;
            server >> message;
            cout << message.number << endl;
        }
    }

    void ClientTest()
    {
        SocketClient client;

        // Connection
        bool isConnected;
        do
        {
            isConnected = client.Connect(localhost, default_port);
            sleep(1);
        }while (!isConnected);

        cout << "Connected to server" << endl;

        // Data transfer
        while (true)
        {
            MessageNum message;
            cin >> message.number;
            client << message;
        }
    }
}
