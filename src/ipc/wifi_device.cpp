#include "wifi_device.hpp"

std::string WiFiDevice::cmd_status()
{
    return "CONNECTED TO " + current_ssid;
}

std::string WiFiDevice::cmd_connect(const std::string& ssid)
{
    current_ssid = ssid;
    connected = true;
    return "OK";
}   
std::string WiFiDevice::cmd_scan()
{
    return "WiFi1,AgroNet,Volna";
}
std::string WiFiDevice::cmd_exit()
{
    return "BYE";
}
