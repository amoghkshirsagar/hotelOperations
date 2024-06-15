#ifndef DEFINE_CONFIG
#define DEFINE_CONFIG
#include <iostream>
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

namespace HOTEL
{
    namespace CONFIG
    {
        json readConfig(std::string name);
        void writeConfig(json config, std::string name);
    }
}

#endif