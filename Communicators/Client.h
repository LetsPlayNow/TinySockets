//
// Created by aleksey on 15.03.17.
//

#ifndef SOCKETLIB_CLIENT_H
#define SOCKETLIB_CLIENT_H

#include "../Connections/Connection.h"

template <class TemplateConnection>
class Client {
public:
    virtual TemplateConnection Connect(const std::string ip, const int port) = 0;
};


#endif //SOCKETLIB_CLIENT_H
