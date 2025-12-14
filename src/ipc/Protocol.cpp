#include "Protocol.hpp"
#include "wifi_device.hpp"


std::string Protocol::handle(std::string& buff)
{
    if(buff == "SCAN")
    {
        return device.cmd_scan();
    }
    
    else if(buff == "CONNECT ")
    {
        std::string ssid = buff.substr(8);
        return device.cmd_connect(ssid);
    }
    else if(buff == "STATUS")
    {
        return device.cmd_status();
    }
    else if(buff == "EXIT")
    {
        return device.cmd_exit();
    }
    return "SUCK";
}
