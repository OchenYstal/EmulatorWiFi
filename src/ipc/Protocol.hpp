#pragma once
#include "wifi_device.hpp"


class Protocol
{
    private:
    WiFiDevice& device;
    
    
    public:
    Protocol(WiFiDevice& dev) : device(dev) {};
    std::string handle(std::string& buff);
    
};
