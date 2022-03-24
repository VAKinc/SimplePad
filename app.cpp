#include <iostream>
#include <windows.h>
#include <map>

#include "./utils/gamepad.h"
#include "./utils/config_parser.h"

using namespace pad2key;

Gamepad pad;
ConfigParser cparser;
int controller_id = 0;
std::map<int, int> bindings = {
    {XINPUT_GAMEPAD_A, KEYBOARD_X}
};

void setup(){
    bindings = cparser.ParseConfigFile(bindings, &controller_id);
    pad = Gamepad(controller_id);
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

        std::map<int, int>::iterator iter;
        for(iter = bindings.begin(); iter != bindings.end(); iter++){
            if(pad.GetButtonDown(iter->first)){
                INPUT inp = {0};
                inp.type = INPUT_KEYBOARD;
                inp.ki.wVk = iter->second;
                inp.ki.wScan = MapVirtualKeyEx(iter->second, MAPVK_VK_TO_VSC, GetKeyboardLayout(0));
                SendInput(1, &inp, sizeof(inp));
            }

            if(pad.GetButtonUp(iter->first)){
                INPUT inp = {0};
                inp.type = INPUT_KEYBOARD;
                inp.ki.wVk = iter->second;
                inp.ki.wScan = MapVirtualKeyEx(iter->second, MAPVK_VK_TO_VSC, GetKeyboardLayout(0));
                inp.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &inp, sizeof(inp));
            }
        }

        if(pad.GetButtonDown(XINPUT_GAMEPAD_START)){
            is_listening = false;
        }
    }
}