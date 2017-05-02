//
// Created by Ahmed Yakout on 5/2/17.
//

#include "assembler.h"

namespace sic_assembler {
    int hex_to_int(std::string hex) {
        return 0;
    }

    std::string decimal_to_hex(int decimal) {
        std::stringstream stream;
        stream << std::setfill ('0') << std::setw(6)
               << std::hex << decimal;
        return stream.str();
    }

    std::string to_lower(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    std::string to_upper(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        return str;
    }

}


