#pragma once
#include "NetworkData.hpp"
#include <vector>
class WAP
{
    public:
    std::vector<WAPData> Load(const std::string& filename);
};