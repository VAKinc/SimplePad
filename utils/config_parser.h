#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <map>
#include <Xinput.h>

#define KEYBOARD_W  0x57
#define KEYBOARD_X  0x58

namespace pad2key{
    class ConfigParser{
        public:
            std::map<int, int> ParseConfigFile(std::map<int, int> bind, int *controller_id);

        private:
            const std::map<std::string, int> _xinput_codes = {
                {"DPAD_DOWN", XINPUT_GAMEPAD_DPAD_DOWN},
                {"DPAD_UP", XINPUT_GAMEPAD_DPAD_UP},
                {"DPAD_LEFT", XINPUT_GAMEPAD_DPAD_LEFT},
                {"DPAD_RIGHT", XINPUT_GAMEPAD_DPAD_RIGHT},
                {"START", XINPUT_GAMEPAD_START},
                {"BACK", XINPUT_GAMEPAD_BACK},
                {"L_STICK", XINPUT_GAMEPAD_LEFT_THUMB},
                {"R_STICK", XINPUT_GAMEPAD_RIGHT_THUMB},
                {"L_BUMPER", XINPUT_GAMEPAD_LEFT_SHOULDER},
                {"R_BUMPER", XINPUT_GAMEPAD_RIGHT_SHOULDER},
                {"A", XINPUT_GAMEPAD_A},
                {"B", XINPUT_GAMEPAD_B},
                {"X", XINPUT_GAMEPAD_X},
                {"Y", XINPUT_GAMEPAD_Y},
            };
            const std::map<std::string, int> _vk_codes = {
                {"shift", VK_SHIFT},
                {"w", KEYBOARD_W}
            };
    };
}

#endif