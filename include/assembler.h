//
// Created by Ahmed Yakout on 5/1/17.
//

#ifndef SIC_XE_ASSEMBLER_ASSEMBLER_H
#define SIC_XE_ASSEMBLER_ASSEMBLER_H

#include <iostream>
#include <iomanip>
#include <sstream>

class sic_assembler {
public:
    static const int INSTRUCTION_LENGTH = 3;
    static int location_counter;
    static int location_counter_old;
    static int starting_address;
    static int program_length;

    static int hex_to_int(std::string hex);
    static std::string decimal_to_hex(int decimal);
    static std::string to_lower(std::string str);
    static std::string to_upper(std::string str);
};

#endif //SIC_XE_ASSEMBLER_ASSEMBLER_H
