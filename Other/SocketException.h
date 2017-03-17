#ifndef SOCKETCLIENT_MYEXCEPTION_H
#define SOCKETCLIENT_MYEXCEPTION_H
#include <exception>
#include <string>
#include <string.h>

struct SocketException : public std::exception
{
    std::string s;
    SocketException(std::string ss) : s(ss)
    {
        s.append("\n");
        s += std::string(strerror(errno));
    }
    ~SocketException() throw () {} // Updated
    const char* what() const throw() { return s.c_str(); }
};

#endif //SOCKETCLIENT_MYEXCEPTION_H
