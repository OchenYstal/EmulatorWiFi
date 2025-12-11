#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   
    char buffer[1024] = {0};
    int r, w;
    int ClientSocket = socket(AF_UNIX, SOCK_STREAM, 0);
    if(ClientSocket == -1)
    {
        std::cerr << "Socket!";
        exit(EXIT_FAILURE);
    }

    sockaddr_un addr;
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, "/tmp/my_socket", sizeof(addr.sun_path) - 1);

        std::string cmd;
        int ret = connect(ClientSocket, (const sockaddr *) & addr, sizeof(addr));
        if(ret == -1)
        {
            fprintf(stderr, "The server is Down!");
            exit(EXIT_FAILURE);
        }
         std::cout << "Connected to server" << std::endl;
         write(ClientSocket, "PING", 5);
         read(ClientSocket, buffer, sizeof(buffer));
         std::cout << buffer;
        close(ClientSocket);  
    return 0;
}
