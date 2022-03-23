#include "gamepad.h"
#include <Xinput.h>

namespace pad2key{
    // Default constructor
    Gamepad::Gamepad() {}
    
    // Overloaded constructor
    Gamepad::Gamepad(int i)
    {
        _index = i;
    }

    XINPUT_STATE Gamepad::GetState()
    {
        XINPUT_STATE state;
        XInputGetState(_index, &state);
    
        return state;
    }

    int Gamepad::GetIndex()
    {
        return _index;
    }

    bool Gamepad::Connected()
    {
        DWORD result = XInputGetState(_index, &_state);

        if (result == 0x0) //ERROR_SUCCESS
            return true;
        else
            return false;
    }
}