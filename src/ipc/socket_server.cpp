#include "socket_server.hpp"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#define SOCKET_NAME "/tmp/my_socket"

SocketServer::SocketServer()
{
    //create socket
    server_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if(server_socket == -1)
    {
        std::cerr << "Cant create a socket!";
        exit(EXIT_FAILURE);
    }
    
    //bind the socket
    sockaddr_un huntaddr;
    memset(&huntaddr, 0, sizeof(huntaddr));
    huntaddr.sun_family = AF_UNIX;
    strncpy(huntaddr.sun_path, SOCKET_NAME, sizeof(huntaddr.sun_path) - 1);
    unlink(SOCKET_NAME);
    if(bind(server_socket, (const sockaddr *) &huntaddr, sizeof(huntaddr)))
    {
        std::cerr << "Cant bind!";
        exit(EXIT_FAILURE);
    }
    if(listen(server_socket, SOMAXCONN) == -1)
    {
        std::cerr << "listen";
        exit(EXIT_FAILURE);
    } 
    std::cout << "Server waiting for conection..." << std::endl;
}
void SocketServer::start(Protocol proto)
{  
    while(true)
    {  
        ClientSocket = accept(server_socket, 0, 0);
        if(ClientSocket == -1)
        {
           std::cerr << "accept!";
          exit(EXIT_FAILURE);
        }
        std::cout << "Client connected!" << std::endl;
        r = read(ClientSocket, buffer, sizeof(buffer));
        buffer[r] = 0;

        std::string cmd(buffer);
        std::cout << cmd << std::endl;
        std::string response = proto.handle(cmd);
        write(ClientSocket, response.c_str(), response.size());
    }
    
    close(server_socket);
    unlink(SOCKET_NAME);
    exit(EXIT_SUCCESS);
}