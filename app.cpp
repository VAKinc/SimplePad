#include <iostream>
#include <windows.h>

#include "gamepad.h"

using namespace pad2key;

Gamepad pad(0);

int main(){
    if(pad.Connected()){
        std::cout << "Connected!\n";
        
    }
    else{
        std::cout << "Not connected.\n";
    }

    bool is_listening = true;
    while(is_listening){
        pad.Update();
        if(pad.GetButtonUp(XINPUT_GAMEPAD_A)){
            INPUT inp = {0};
            inp.type = INPUT_KEYBOARD;
            inp.ki.wVk = 0x57;
            inp.ki.wScan = MapVirtualKeyEx(0x57, 0, (HKL)0xf0010413);
            SendInput(1, &inp, sizeof(inp));
        }

        if(pad.GetButtonDown(XINPUT_GAMEPAD_START)){
            is_listening = false;
        }
    }
}