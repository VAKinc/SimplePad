#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include "../models/config.h"

namespace pad2key{
    class ConfigParser{
        public:
            void ParseConfigFile(Config *config);
            int ParseStringToVKCode(std::string value);
    };
}

#endif