//
// Created by Ahmed Yakout on 5/2/17.
//

#include "assembler.h"


int sic_assembler::location_counter = 0;
int sic_assembler::location_counter_old = 0;
int sic_assembler::starting_address = 0;
int sic_assembler::program_length = 0;

int sic_assembler::hex_to_int(std::string hex) {
    unsigned int i;
    std::stringstream ss;
    ss << std::hex << hex;
    ss >> i;
    return i;
}

std::string sic_assembler::decimal_to_hex(int decimal, int width) {
    std::stringstream stream;
    stream << std::setfill('0');
    if (width > 0) {
        stream << std::setw(width);
    }
    stream << std::hex << decimal;
    return stream.str();
}

std::string sic_assembler::to_lower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

std::string sic_assembler::to_upper(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

std::string sic_assembler::trim(std::string str){
    int start = 0, end = (int) str.length();
    while (start < end && str[start] == ' '){
        start++;
    }
    while (start < end && str[end] == ' '){
        end--;
    }
    return str.substr((unsigned int) start, (unsigned int) end - start + 1);
}
