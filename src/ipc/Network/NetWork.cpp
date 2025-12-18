#include "NetWork.hpp"
#include "NetworkData.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

std::vector<WAPData> WAP::Load(const std::string& filename)
{
    std::ifstream file(filename);
    json j;
    file >> j;

    std::vector<WAPData> result;

    for (auto& net : j["networks"])
    {
        WAPData object;
        object.SSID = net["SSID"];
        object.IP = net["IP"];
        object.signal_strength = net["dBm"];
        object.security = net["security"];

        result.push_back(object);
    }
    return result;
}