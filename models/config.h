#ifndef CONFIG_H
#define CONFIG_H

namespace pad2key{
    struct Config{
        int pad_id;
        int dpad_down;
        int dpad_up; 
        int dpad_left;
        int dpad_right;
        int start;
        int back;
        int l_stick;
        int r_stick;
        int l_bumper;
        int r_bumper;
        int a;
        int b;
        int x;
        int y;
    };
}

#endif