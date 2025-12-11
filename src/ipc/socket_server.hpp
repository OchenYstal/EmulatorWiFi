#pragma once
#include <sys/types.h>

class SocketServer
{
private:
    int ret;
    int ClientSocket;
    int server_socket;
    int down_flag = 0;
    ssize_t r, w;
    
    char buffer[1024] = {0};
public:
    SocketServer();
    void start();
};