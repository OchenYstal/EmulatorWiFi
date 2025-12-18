#pragma once
#include <string>

struct WAPData
{
    std::string SSID;
    std::string IP;
    int signal_strength;
    std::string security;
};