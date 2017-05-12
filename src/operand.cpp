//
// Created by Ahmed Yakout on 4/23/17.
//

#include <vector>
#include <assembler.h>
#include <operand.h>
#include <regex_patterns.h>
#include <tables/sym_table.h>
#include <tables/lit_table.h>
#include <regex>
#include <errors/pass_one/invalid_operand.h>
#include <errors/pass_one/operand_out_of_range.h>
#include <errors/pass_two/undefined_symbol.h>

operand::operand(std::string operand_field) {
    operand_field = sic_assembler::trim(operand_field);
    name = operand_field;

    if (operand_field == "*") {
        operand::type = operand::operand_type::LOC_COUNTER;
        operand::opcode = sic_assembler::decimal_to_hex(sic_assembler::location_counter, operand::OPERAND_WIDTH);
    }
    else if (regex_match(operand_field, std::regex(EMPTY_STRING_PATTERN))){
        operand::type = operand::operand_type::NONE;
        operand::opcode = "";
    }
    else if (regex_match(operand_field, std::regex(DECIMAL_PATTERN))){
        operand::type = operand::operand_type::DECIMAL;
        int address = stoi(operand_field);
        if (address > operand::MAX_DECIMAL_ADDRESS){
            throw operand_out_of_range();
        }
        operand::opcode = sic_assembler::decimal_to_hex(address, operand::OPERAND_WIDTH);
    }
    else if (regex_match(operand_field, std::regex(HEXA_PATTERN))){
        operand::type = operand::operand_type::HEXA;
        int address = sic_assembler::hex_to_int(operand_field.substr(2, operand_field.length() - 2));
        if (address > operand::MAX_DECIMAL_ADDRESS){
            throw operand_out_of_range();
        }
        operand::opcode = sic_assembler::decimal_to_hex(address, operand::OPERAND_WIDTH);
    }
    else if (regex_match(operand_field, std::regex(DECIMAL_ARRAY_PATTERN))){
        operand::type = operand::operand_type::DECIMAL_ARRAY;
        std::string temp = "";
        int prev = 0;
        int num;
        for (int i = 0; i < operand_field.length(); i++) {
            if (operand_field[i] == ',') {
                num = stoi(operand_field.substr(prev, i - prev));
                temp += sic_assembler::decimal_to_hex(num, operand::OPERAND_WIDTH) + ",";
                prev = i + 1;
            }
        }
        num = stoi(operand_field.substr(prev, operand_field.length() - prev));
        temp += sic_assembler::decimal_to_hex(num, operand::OPERAND_WIDTH);
        operand::opcode = temp;
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
    else if (regex_match(operand_field, std::regex(HEXA_STRING_PATTERN))) {
        operand::type = operand::operand_type::HEXA_STRING;
        int address = sic_assembler::hex_to_int(operand_field.substr(2, operand_field.length() - 3));
        if (address > operand::MAX_DECIMAL_ADDRESS) {
            throw operand_out_of_range();
        }
        operand::opcode = sic_assembler::decimal_to_hex(address, operand_field.length() - 3); // -3 to remove X''
    }
    else if (regex_match(operand_field, std::regex(EXPRESSION_PATTERN))){
        operand::type = operand::operand_type::EXPRESSION;
    }
    else if (regex_match(operand_field, std::regex(WORD_LITERAL_PATTERN))){
        operand::type = operand::operand_type::WORD_LITERAL;
    }
    else if (regex_match(operand_field, std::regex(CHAR_LITERAL_PATTERN))){
        operand::type = operand::operand_type::CHAR_LITERAL;
    }
    else if (regex_match(operand_field, std::regex(HEXA_LITERAL_PATTERN))){
        operand::type = operand::operand_type::HEXA_LITERAL;
    }
    else {
        throw invalid_operand();
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

bool operand::is_literal() {
    return (type == operand::operand_type::CHAR_LITERAL || type == operand::operand_type::HEXA_LITERAL
                        || type == operand::operand_type::WORD_LITERAL);
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
    // calculate operand only once
    if (operand::opcode != "" || operand::get_type() == operand::operand_type::NONE) {
        return operand::opcode;
    }

    if (type == operand_type::LABEL) {
        if (!sym_table::get_instance().lookup(name)) {
            throw undefined_symbol();
        } else {
            operand::opcode = sic_assembler::decimal_to_hex(sym_table::get_instance().get(name), operand::OPERAND_WIDTH);
        }
    } else if (type == operand_type::LABEL_INDEXED) {
        std::size_t found = name.find(",");
        if (!sym_table::get_instance().lookup(name.substr(0, found))) {
            throw undefined_symbol();
        } else {
            operand::opcode = sic_assembler::decimal_to_hex((1 << 15) 
                            + sym_table::get_instance().get(name), operand::OPERAND_WIDTH);
        }
    } else if (type == operand_type::EXPRESSION){
        int f = 0;
        std::string a;
        std::string b;
        for (int i = 0; i < name.length(); i++){
            if (name[i] == '+'){
                f = 1;
            }
            else if (name[i] == '-'){
                f = -1;
            }
            if (f != 0){
                a = name.substr(0, i);
                b = name.substr(i+1, name.length() - i);
                break;
            }
        }
        if (f != 0){
            operand *u = new operand(a);
            operand *v = new operand(b);
            if (u->get_type() != operand_type::DECIMAL && u->get_type() != operand_type::LABEL){
                throw "invalid expression";
            }
            if (v->get_type() != operand_type::DECIMAL && v->get_type() != operand_type::LABEL){
                throw "invalid expression";
            }
            operand::opcode = sic_assembler::decimal_to_hex(sic_assembler::hex_to_int(u->get_opcode()) + f * sic_assembler::hex_to_int(v->get_opcode()), OPERAND_WIDTH);
        }
        else {
            throw "invalid expression";
        }
    } else if(type == operand::operand_type::HEXA_LITERAL || type == operand::operand_type::CHAR_LITERAL
                                        || type == operand::operand_type::WORD_LITERAL) {
        operand::opcode = sic_assembler::decimal_to_hex(lit_table::get_instance().get(name), operand::OPERAND_WIDTH);
    }
    return operand::opcode;
}
