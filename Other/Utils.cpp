//
// Created by aleksey on 25.12.16.
//
#include "Utils.h"

void Sleep(int miliseconds) { sleep(miliseconds / 1000); }
void closesocket(int socket_desc) { close(socket_desc); }
