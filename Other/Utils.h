#pragma once
#ifdef __linux__

#include <unistd.h>
#include <sys/socket.h>
void Sleep(int miliseconds) { sleep(miliseconds / 1000); }
void closesocket(int socket_desc) { close(socket_desc); }
#endif
