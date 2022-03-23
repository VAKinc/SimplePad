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
        
            void Update();
            XINPUT_STATE GetState();
            int GetIndex();
            bool Connected();
            bool GetButtonPressed(int button);

        private:
            XINPUT_STATE _state;
            XINPUT_STATE _prev_state;
            int _index;
    };
    
}

#endif // GAMEPAD_H
