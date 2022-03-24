#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <map>

#include "config_parser.h"

namespace pad2key{
    std::map<int, int> ConfigParser::ParseConfigFile(int *controller_id){
        std::ifstream ifs("config.ini");

        if(!ifs.good()){
            throw std::runtime_error("Cannot open config.ini, is the file missing?");
        }

        std::map<int, int> bind;

        for(;;) {
            std::string line;
            std::getline(ifs, line);
            if(!ifs) break;
            int delim = line.find("=");
            std::string key = line.substr(0, delim);
            std::string value = line.substr(delim + 1, line.length());
            
            if(key == "CONTROLLER_ID"){
                int v = std::stoi(value);
                if(v > 0 && v <= 4) *controller_id = v - 1;
                else throw std::invalid_argument("Invalid controller ID setting (valid options a 1~4).");
            }
            else {
                if(_xinput_codes.count(key) && _vk_codes.count(value)){
                    auto iter = _xinput_codes.find(key);
                    int xinput = iter->second;
                    iter = _vk_codes.find(value);
                    int keyboard = iter->second;
                    bind.insert({xinput, keyboard});

                    std::cout << "Bound " << key << " to " << value << std::endl;
                }
            }
        }
        if(!ifs.eof()){
            throw std::runtime_error("Error reading config.");
        }

        return bind;
    }

    int ConfigParser::ParseStringToVKCode(std::string s){
        //TODO
        return 0x57;
    }
}