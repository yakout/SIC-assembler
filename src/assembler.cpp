//
// Created by Ahmed Yakout on 5/2/17.
//

#include "assembler.h"


int sic_assembler::location_counter = 0;
int sic_assembler::location_counter_old = 0;
int sic_assembler::starting_address = 0;
int sic_assembler::program_length = 0;
std::string sic_assembler::program_name = "";
const std::string sic_assembler::directives[] { "start", "end", "resw", "resb", "word", "byte"};

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
//    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    bool string_start = false;
    for (int i = 0; i < str.length(); i++){
        if (str[i] >= 'A' && str[i] <= 'Z' && !string_start){
            str[i] = ('a' + str[i] - 'A');
        }
        if (i && str[i] == '\'' && str[i-1] == 'c' && !string_start){
            string_start = true;
        }
        else if (str[i] == '\'' && string_start){
            string_start = false;
        }
    }
    return str;
}

std::string sic_assembler::to_upper(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

std::string sic_assembler::trim(std::string str) {
    int start = 0, end = (int) str.length() - 1;
    while (start < end && str[start] == ' '){
        start++;
    }
    while (start < end && str[end] == ' '){
        end--;
    }
    return str.substr((unsigned int) start, (unsigned int) end - start + 1);
}

bool sic_assembler::is_directive(std::string directive) {
    for (std::string dir : directives) {
        if (directive == dir) {
            return true;
        }
    }
    return false;
}

std::string sic_assembler::remove_tabs(std::string str){
    std::string str_new = "";
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '\t'){
            for (int j = 0; j < sic_assembler::TAB_WIDTH - (i % sic_assembler::TAB_WIDTH); j++){
                str_new += ' ';
            }
        }
        else {
            str_new += str[i];
        }
    }
    return str_new;
}
