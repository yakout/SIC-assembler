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
    name = operand_field;

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
    }
    else if (regex_match(operand_field, std::regex(LABEL_INDEXED_PATTERN))){
        operand::type = operand::operand_type::LABEL_INDEXED;
        operand_field = operand_field.substr(0, operand_field.length() - 2);  // -2 to remove ,X
    }
    else if (regex_match(operand_field, std::regex(STRING_PATTERN))){
        operand::type = operand::operand_type::STRING;
        operand::opcode = "";
        for (int i = 2; i < operand_field.length() - 1; i++){
            operand::opcode += sic_assembler::decimal_to_hex((int) operand_field[i], 2);
        }
    }
    else if (regex_match(operand_field, std::regex(HEXA_STRING_PATTERN))){
        operand::type = operand::operand_type::HEXA_STRING;
        int address = sic_assembler::hex_to_int(operand_field.substr(2, operand_field.length() - 3));
        if (address > operand::MAX_DECIMAL_ADDRESS){
            throw "Out of range [0, 65535]";
        }
        operand::opcode = sic_assembler::decimal_to_hex(address, operand_field.length() - 3); // -3 to remove X''
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


operand::~operand() {

}

std::string operand::get_name() {
    return name;
}

operand::operand_type operand::get_type() {
    return operand::type;
}

int operand::get_length() {
    if (name[0] == 'c') {
        return (int) name.length() - 3; // -3 to remove c'' chars.
    } else if (name[0] == 'x') {
        return (int) ((name.length() - 3) / 2); // -3 to remove X'' and since two hex digits is one byte we divide by 2
    }
    return (int) name.length();
}

std::string operand::get_opcode() {
    if (type == operand_type::LABEL) {
        operand::opcode = sic_assembler::decimal_to_hex(sym_table::get_instance()->get(name), operand::OPERAND_WIDTH);
    } else if (type == operand_type::LABEL_INDEXED) {
        operand::opcode = sic_assembler::decimal_to_hex((1 << 15) + sym_table::get_instance()->get(name), operand::OPERAND_WIDTH);
    }
    return operand::opcode;
}
