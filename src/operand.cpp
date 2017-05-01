//
// Created by Ahmed Yakout on 4/23/17.
//

#include "operand.h"

operand::operand(std::string abcdefg) {
    // todo
}

bool operand::is_indexing() {
    return false;
}

bool operand::is_indirect() {
    return false;
}

bool operand::is_immediate() {
    return false;
}

std::string operand::get_name() {
    return name;
}

bool operand::is_hex_address() {
    return false;
}

bool operand::is_direct() {
    return false;
}

int operand::get_length() {
    //todo
    return 0;
}
