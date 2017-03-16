//
// Created by aleksey on 16.03.17.
//

#ifndef SOCKETLIB_MYCONNECTION_H
#define SOCKETLIB_MYCONNECTION_H

#include "../Connections/Connection.h"

// TODO Add string and array to this example
class MyConnection : public Connection{
    friend Connection & operator <<(Connection & connection, const char symbol)
    {
        connection._socket->Send(&number, sizeof(int));
        return connection;
    }

    friend Connection & operator >>(Connection & connection, char & symbol)
    {
        connection._socket->Recv(&number, sizeof(int));
        return connection;
    }
};


#endif //SOCKETLIB_MYCONNECTION_H
