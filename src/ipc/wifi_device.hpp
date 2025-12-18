#pragma once
#include <string>
#include "Network/NetWork.hpp"

class WiFiDevice
{
     private:
     std::string status;
     std::string ssid;
     std::string current_ssid;
     bool connected = false;
     public:
     std::string cmd_status();
     std::string cmd_connect(const std::string& arg);
     std::string cmd_exit();
     std::string cmd_scan();
     
};