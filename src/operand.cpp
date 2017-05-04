//
// Created by Ahmed Yakout on 4/23/17.
//

#include "assembler.h"
#include "operand.h"
#include "regex_patterns.h"
#include "sym_table.h"
#include <regex>

operand::operand(std::string operand_field) {
    operand_field = sic_assembler::trim(operand_field);

    if (operand_field == "*"){
        operand::type = operand::operand_type::LOC_COUNTER;
        operand::opcode = sic_assembler::decimal_to_hex(sic_assembler::location_counter, operand::OPERAND_WIDTH);
    }
    else if (regex_match(operand_field, std::regex(DECIMAL_PATTERN))){
        operand::type = operand::operand_type::DECIMAL_ADDRESS;
        int address = stoi(operand_field);
        if (address > operand::MAX_DECIMAL_ADDRESS){
            throw "Out of range [0, 65535]";
        }
        operand::opcode = sic_assembler::decimal_to_hex(address, operand::OPERAND_WIDTH);
    }
    else if (regex_match(operand_field, std::regex(HEXA_PATTERN))){
        operand::type = operand::operand_type::HEXA_ADDRESS;
        int address = sic_assembler::hex_to_int(operand_field.substr(2, operand_field.length() - 2));
        if (address > operand::MAX_DECIMAL_ADDRESS){
            throw "Out of range [0, 65535]";
        }
        operand::opcode = sic_assembler::decimal_to_hex(address, operand::OPERAND_WIDTH);
    }
    else if (regex_match(operand_field, std::regex(LABEL_PATTERN))){
        operand::type = operand::operand_type::LABEL;
        if (sym_table::get_instance()->lookup(operand_field)){
            operand::opcode = sic_assembler::decimal_to_hex(sym_table::get_instance()->get(operand_field), operand::OPERAND_WIDTH);
        }
        else {
            throw "Invalid label";
        }
    }
    else if (regex_match(operand_field, std::regex(LABEL_INDEXED_PATTERN))){
        operand::type = operand::operand_type::LABEL_INDEXED;
        operand_field = operand_field.substr(0, operand_field.length() - 2);
        if (sym_table::get_instance()->lookup(operand_field)){
            operand::opcode = sic_assembler::decimal_to_hex((1 << 15) + sym_table::get_instance()->get(operand_field), operand::OPERAND_WIDTH);
        }
        else {
            throw "Invalid label";
        }
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

std::string operand::get_opcode(){
    return operand::opcode;
}
