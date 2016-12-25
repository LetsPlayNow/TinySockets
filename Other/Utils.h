#pragma once
#ifdef __linux__

#include <unistd.h>
#include <sys/socket.h>
void Sleep(int miliseconds);
void closesocket(int socket_desc);
#endif
