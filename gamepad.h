#ifndef GAMEPAD_H
#define GAMEPAD_H
 
#include <Xinput.h>
#pragma once
 
namespace pad2key{
    class Gamepad
    {
        public:
            Gamepad();
            Gamepad(int i);
        
            XINPUT_STATE GetState();
            int GetIndex();
            bool Connected();

        private:
            XINPUT_STATE _state;
            int _index;
    };
    
}

#endif // GAMEPAD_H
