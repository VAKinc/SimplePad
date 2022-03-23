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

    std::cout << "Press 'Enter' to exit.";
    std::cin.get();
}