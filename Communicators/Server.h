//
// Created by aleksey on 15.03.17.
//

#ifndef SOCKETLIB_SERVER_H
#define SOCKETLIB_SERVER_H

#include "../Connections/Connection.h"

template <class TemplateConnection>
class Server {
public:
    virtual TemplateConnection AcceptConnection() = 0;
};


#endif //SOCKETLIB_SERVER_H
