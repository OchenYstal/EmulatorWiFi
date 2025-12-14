#include "ipc/socket_server.hpp"
#include "ipc/wifi_device.hpp"


int main()
{
    WiFiDevice device;
    Protocol protoc(device);
    SocketServer server;  
    server.start(protoc);
    return 0;
}