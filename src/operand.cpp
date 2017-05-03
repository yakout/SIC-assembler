//
// Created by Ahmed Yakout on 4/23/17.
//

#include "operand.h"
#include "regex_patterns.h"
#include <regex>

operand::operand(std::string operand_field) {
    if (operand_field == "*"){
        operand::type = operand::operand_type::LOC_COUNTER;
    }
    else if (regex_match(operand_field, std::regex(DECIMAL_PATTERN))){
        operand::type = operand::operand_type::DECIMAL_ADDRESS;
    }
    else if (regex_match(operand_field, std::regex(HEXA_PATTERN))){
        operand::type = operand::operand_type::HEXA_ADDRESS;
    }
    else if (regex_match(operand_field, std::regex(LABEL_PATTERN))){
        operand::type = operand::operand_type::LABEL;
    }
    else if (regex_match(operand_field, std::regex(LABEL_INDEXED_PATTERN))){
        operand::type = operand::operand_type::LABEL_INDEXED;
    }
    else if (regex_match(operand_field, std::regex(REGISTER_PATTERN))){
        operand::type = operand::operand_type::REGISTER;
    }
    else if (regex_match(operand_field, std::regex(TWO_REGISTERS_PATTERN))){
        operand::type = operand::operand_type::TWO_REGISTERS;
    }
    else if (regex_match(operand_field, std::regex(EXPRESSION_PATTERN))){
        operand::type = operand::operand_type::EXPRESION;
    }
    else if (regex_match(operand_field, std::regex(WORD_LITERAL_PATTERN))){
        operand::type = operand::operand_type::WORD_LITERAL;
    }
    else if (regex_match(operand_field, std::regex(HEXA_LITERAL_PATTERN))){
        operand::type = operand::operand_type::HEXA_LITERAL;
    }
    else {
        throw "Invalid operand";
    }
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

void operand::set_type(operand::operand_type type) {
    operand::type = type;
}

operand::operand_type operand::get_type() {
    return operand::type;
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

operand::operand_type operand::get_type() {
    return type;
}
