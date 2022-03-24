#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <map>

#include "gamepad.h"

using namespace pad2key;

Gamepad pad;
std::map<std::string, std::string> bindings;

std::string GetValueAtKey(std::string key){
    auto iter = bindings.find(key);
    if (iter != bindings.end()){
        return iter->second;
    }
    else{
        return "";
    }
}

void setup(){
    pad = Gamepad();
    std::ifstream ifs("config.ini");

    if(!ifs.good()){
        throw std::runtime_error("Cannot open config.ini, is the file missing?");
    }

    for(;;) {
        std::string line;
        std::getline(ifs, line);
        if(!ifs) break;
        int delim = line.find("=");
        bindings.insert(std::pair<std::string, std::string>(line.substr(0, delim), line.substr(delim + 1, line.length())));
    }
    if(!ifs.eof()){
        throw std::runtime_error("Error reading config.");
    }

    int pad_no = std::stoi(GetValueAtKey("CONTROLLER_ID")) - 1;
    if(pad_no > 3 || pad_no < 0){
        throw std::runtime_error("Invalid pad ID.");
    }

    pad = Gamepad(pad_no);
}

int main(){
    setup();

    if(pad.Connected()){
        std::cout << "Connected!\n";
    }
    else{
        std::cout << "Not connected.\n";
        return 0;
    }

    bool is_listening = true;
    while(is_listening){
        pad.Update();
        if(pad.GetButtonUp(XINPUT_GAMEPAD_A)){
            INPUT inp = {0};
            inp.type = INPUT_KEYBOARD;
            inp.ki.wVk = 0x57;
            inp.ki.wScan = MapVirtualKeyEx(0x57, MAPVK_VK_TO_VSC, GetKeyboardLayout(0));
            SendInput(1, &inp, sizeof(inp));
        }

        if(pad.GetButtonDown(XINPUT_GAMEPAD_START)){
            is_listening = false;
        }
    }
}