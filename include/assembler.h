//
// Created by Ahmed Yakout on 5/1/17.
//

#ifndef SIC_XE_ASSEMBLER_ASSEMBLER_H
#define SIC_XE_ASSEMBLER_ASSEMBLER_H

#include <iostream>

namespace sic_assembler {
    const int INSTRCUTION_LENGTH = 3;
    int location_counter;
    int starting_address;
    int program_length;
    int hex_to_int(std::string hex) {
        return 0;
    }
    std::string to_lower(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), std::tolower);
        return str;
    }
    std::string to_upper(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), std::toupper);
        return str;
    }
}

#endif //SIC_XE_ASSEMBLER_ASSEMBLER_H
