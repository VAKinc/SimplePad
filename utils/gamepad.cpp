#include <Xinput.h>
#include <iostream>

#include "gamepad.h"

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
        return _state;
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

    bool Gamepad::GetButtonUp(int button)
    {
        if ((_prev_state.Gamepad.wButtons & button) && !(_state.Gamepad.wButtons & button))
        {
            return true;
        }
 
        return false;
    }

    bool Gamepad::GetButtonDown(int button)
    {
        if (!(_prev_state.Gamepad.wButtons & button) && (_state.Gamepad.wButtons & button))
        {
            return true;
        }
 
        return false;
    }

    bool Gamepad::GetButton(int button)
    {
        if (_state.Gamepad.wButtons & button)
        {
            return true;
        }
 
        return false;
    }

    void Gamepad::Update()
    {
        XINPUT_STATE state;
        XInputGetState(_index, &state);

        _prev_state = _state;
        _state = state;
        
    }
}