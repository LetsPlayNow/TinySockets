#include "Tests.h"

std::string Test::localhost = "127.0.0.1";
int Test::default_port = 50000;

bool Test::shouldSendReceive() {
    SocketServer server(default_port);
    SocketClient client;

    client.TryConnect(localhost, default_port);
    server.TryAcceptConnection();   

    MessageNum messageSent(13);
    client << messageSent;

    MessageNum messageRecv;
    server >> messageRecv;

    client.Disconnect();
    bool success = messageRecv.number == messageSent.number;
    return success;
}

bool Test::shouldRecvFirst() {
    SocketServer server(default_port);
    SocketClient client;

    client.TryConnect(localhost, default_port);
    server.TryAcceptConnection();
 

    client << MessageNum(10);
    client << MessageNum(15);

    MessageNum recieved;
    server >> recieved;

    return recieved.number == 10;
}

bool Test::shouldNotRecvAfterClientTermination() {
    SocketServer server(default_port);
    SocketClient client;

    client.TryConnect(localhost, default_port);
    server.TryAcceptConnection();

    MessageNum message(110);
    client << message;
    client.Disconnect();

    MessageNum recieved;
    try {
        server >> recieved;
        server >> recieved;
    }
    catch (SocketException e) {
        return true;
    }

    return false;
}

void Test::RunAlltests() {
    cout << "Should send recv: " << std::boolalpha << 
        shouldSendReceive() << endl;
    cout << "Should recieve first message: " << 
        shouldRecvFirst() << endl;
    cout << "Should not recv after client termination: " << 
        shouldNotRecvAfterClientTermination() << endl;
}

void Test::ServerTest()
{
    SocketServer server(default_port);
    server.AcceptConnection();

    cout << "Client connected" << endl;

    // Data transfer
    while (true)
    {
        MessageNum message;
        server >> message;
        cout << message.number << endl;
    }
}

void Test::ClientTest()
{
    SocketClient client;
    client.Connect(localhost, default_port);

    cout << "Connected to server" << endl;

    // Data transfer
    while (true)
    {
        MessageNum message;
        cin >> message.number;
        client << message;
    }
}
