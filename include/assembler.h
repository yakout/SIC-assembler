//
// Created by Ahmed Yakout on 5/1/17.
//

/**
 *   A S S U M P T I O N S
 *   any hex value must be in the form 0x[hex value]
 *
 */


/**
 *  TODO
 *  support tabs with spaces
 *
 */

#ifndef SIC_XE_ASSEMBLER_ASSEMBLER_H
#define SIC_XE_ASSEMBLER_ASSEMBLER_H



#include <iostream>
#include <iomanip>
#include <sstream>

class sic_assembler {
public:
    static const int INSTRUCTION_LENGTH = 3;
    static int location_counter;
    static int location_counter_old; // phase 2
    static int starting_address;
    static int program_length;
    static const std::string directives[];

    static int hex_to_int(std::string hex);
    static std::string decimal_to_hex(int decimal, int width = -1);
    static std::string to_lower(std::string str);
    static std::string to_upper(std::string str);
    static std::string trim(std::string str);
    static bool is_directive(std::string);
};

#endif //SIC_XE_ASSEMBLER_ASSEMBLER_H
