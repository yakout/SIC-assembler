//
// Created by Ahmed Yakout on 5/1/17.
//

#ifndef SIC_XE_ASSEMBLER_ASSEMBLER_H
#define SIC_XE_ASSEMBLER_ASSEMBLER_H

#include <iostream>
#include <iomanip>
#include <sstream>

namespace sic_assembler {
    const int INSTRCUTION_LENGTH = 3;
    int location_counter;
    int starting_address;
    int program_length;
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

#endif //SIC_XE_ASSEMBLER_ASSEMBLER_H
