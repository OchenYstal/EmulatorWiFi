#pragma once
#include <sys/types.h>
#include "Protocol.hpp"



class SocketServer
{
private:
    int ret;
    int ClientSocket;
    int server_socket;
    ssize_t r, w;
    char buffer[1024] = {0};
public:
    SocketServer();
    void start(Protocol proto);
};