#include <iostream>
#include "config.hxx"
#include "json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;

namespace HOTEL
{
    namespace CONFIG
    {
        void writeConfig(json jConfig, std::string fname)
        {
            ofstream config(fname);
            config << std::setw(4) << jConfig;
        }

    }
}