#include "Tests.h"

namespace Test
{
    std::string default_ip = "127.0.0.1";
    int default_port = 50000;

    void TcpSendRecvTest()
    {
        TCPServer<Connection> server(default_port);
        TCPClient<Connection> client;

        Connection client_connection = client.Connect(default_ip, default_port);
        Connection server_connection = server.AcceptConnection();

        int buffer_in = 12345;
        client_connection << buffer_in;

        int buffer_out;
        server_connection >> buffer_out;

        assert(buffer_in == buffer_out);

        buffer_in = 54321;
        server_connection << buffer_in << buffer_in;

        buffer_out;
        client_connection >> buffer_out;
        assert(buffer_in == buffer_out);
        client_connection >> buffer_out;
        assert(buffer_in == buffer_out);
    }

    void UdpSendRecvTest()
    {
        UDPServer<Connection> server(default_port);
        UDPClient<Connection> client;

        Connection server_connection = server.AcceptConnection();
        Connection client_connection = client.Connect(default_ip, default_port);

        int buffer_in = 12345;
        client_connection << buffer_in;

        int buffer_out;
        server_connection >> buffer_out;

        assert(buffer_in == buffer_out);

        buffer_in = 54321;
        server_connection << buffer_in << buffer_in;

        buffer_out;
        client_connection >> buffer_out;
        assert(buffer_in == buffer_out);
        client_connection >> buffer_out;
        assert(buffer_in == buffer_out);
    }
}

