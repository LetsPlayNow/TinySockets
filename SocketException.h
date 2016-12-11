//
// Created by aleksey on 09.10.16.
//

#ifndef SOCKETCLIENT_MYEXCEPTION_H
#define SOCKETCLIENT_MYEXCEPTION_H
#include <exception>
#include <string>

struct SocketException : public std::exception
{
    std::string s;
    SocketException(std::string ss) : s(ss) {}
    ~SocketException() throw () {} // Updated
    const char* what() const throw() { return s.c_str(); }
};

#endif //SOCKETCLIENT_MYEXCEPTION_H
