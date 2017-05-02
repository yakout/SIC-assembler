//
// Created by Ahmed Yakout on 5/1/17.
//

#ifndef SIC_XE_ASSEMBLER_ASSEMBLER_H
#define SIC_XE_ASSEMBLER_ASSEMBLER_H

#include <iostream>
#include <iomanip>
#include <sstream>

namespace sic_assembler {
    const int INSTRUCTION_LENGTH = 3;
    int location_counter;
    int starting_address;
    int program_length;

    int hex_to_int(std::string hex);
    std::string decimal_to_hex(int decimal);
    std::string to_lower(std::string str);
    std::string to_upper(std::string str);
}

#endif //SIC_XE_ASSEMBLER_ASSEMBLER_H
