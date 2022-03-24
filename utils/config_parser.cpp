#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

#include "config_parser.h"
#include "../models/config.h"

namespace pad2key{
    void ConfigParser::ParseConfigFile(Config *config){
        std::ifstream ifs("config.ini");

        if(!ifs.good()){
            throw std::runtime_error("Cannot open config.ini, is the file missing?");
        }
        Config c = *config;
        for(;;) {
            std::string line;
            std::getline(ifs, line);
            if(!ifs) break;
            int delim = line.find("=");
            std::string key = line.substr(0, delim);
            std::string value = line.substr(delim + 1, line.length());
            
            if(key == "CONTROLLER_ID"){
                int v = std::stoi(value);
                if(v > 0 && v <= 4) c.pad_id = v - 1;
                else throw std::invalid_argument("Invalid controller ID setting (valid options a 1~4).");
            }
            else if(key == "DPAD_DOWN"){
                c.dpad_down = ParseStringToVKCode(value);
            }
            else if(key == "DPAD_UP"){
                c.dpad_up = ParseStringToVKCode(value);
            }
            else if(key == "DPAD_LEFT"){
                c.dpad_left = ParseStringToVKCode(value);
            }
            else if(key == "DPAD_RIGHT"){
                c.dpad_right = ParseStringToVKCode(value);
            }
            else if(key == "START"){
                c.start = ParseStringToVKCode(value);
            }
            else if(key == "BACK"){
                c.back = ParseStringToVKCode(value);
            }
            else if(key == "L_STICK"){
                c.l_stick = ParseStringToVKCode(value);
            }
            else if(key == "R_STICK"){
                c.r_stick = ParseStringToVKCode(value);
            }
            else if(key == "L_BUMPER"){
                c.l_bumper = ParseStringToVKCode(value);
            }
            else if(key == "R_BUMPER"){
                c.r_bumper = ParseStringToVKCode(value);
            }
            else if(key == "A"){
                c.a = ParseStringToVKCode(value);
            }
            else if(key == "B"){
                c.b = ParseStringToVKCode(value);
            }
            else if(key == "X"){
                c.x = ParseStringToVKCode(value);
            }
            else if(key == "Y"){
                c.y = ParseStringToVKCode(value);
            }
        }
        if(!ifs.eof()){
            throw std::runtime_error("Error reading config.");
        }

        *config = c;
    }

    int ConfigParser::ParseStringToVKCode(std::string s){
        //TODO
        return 0x57;
    }
}