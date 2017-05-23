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
#include <expression_evaluator.h>

operand::operand(std::string operand_field) {
    operand_field = sic_assembler::trim(operand_field);
    name = operand_field;

    if (operand_field == "*") {
        operand::type = operand::operand_type::LOC_COUNTER;
    }
    else if (regex_match(operand_field, std::regex(EMPTY_STRING_PATTERN))){
        operand::type = operand::operand_type::NONE;
        operand::address = "0000";
    }
    else if (regex_match(operand_field, std::regex(DECIMAL_PATTERN))){
        operand::type = operand::operand_type::DECIMAL;
        int address = stoi(operand_field);
        if (address > operand::MAX_DECIMAL_ADDRESS){
            throw operand_out_of_range();
        }
        operand::address = sic_assembler::decimal_to_hex(address, operand::OPERAND_WIDTH);
    }
    else if (regex_match(operand_field, std::regex(HEXA_PATTERN))){
        operand::type = operand::operand_type::HEXA;
        int address = sic_assembler::hex_to_int(operand_field.substr(2, operand_field.length() - 2));
        if (address > operand::MAX_DECIMAL_ADDRESS){
            throw operand_out_of_range();
        }
        operand::address = sic_assembler::decimal_to_hex(address, operand::OPERAND_WIDTH);
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
        operand::address = temp;
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
        operand::address = "";
        for (int i = 2; i < operand_field.length() - 1; i++){
            operand::address += sic_assembler::decimal_to_hex((int) operand_field[i], 2);
        }
    }
    else if (regex_match(operand_field, std::regex(HEXA_STRING_PATTERN))) {
        operand::type = operand::operand_type::HEXA_STRING;
        int address = sic_assembler::hex_to_int(operand_field.substr(2, operand_field.length() - 3));
        if (address > operand::MAX_DECIMAL_ADDRESS) {
            throw operand_out_of_range();
        }
        operand::address = sic_assembler::decimal_to_hex(address, operand_field.length() - 3); // -3 to exclude length of X''
    }
    else if (regex_match(operand_field, std::regex(EXPRESSION_PATTERN))){
        operand::type = operand::operand_type::EXPRESSION;
    }


    // CHECK LITERALS
    else if (regex_match(operand_field, std::regex(WORD_LITERAL_PATTERN))){
        // remove the '='
        int address = stoi(operand_field.substr(1));
        // check value for out of range error.
        if (address > operand::MAX_DECIMAL_ADDRESS){
            throw operand_out_of_range();
        }
        operand::type = operand::operand_type::WORD_LITERAL;
    }
    else if (regex_match(operand_field, std::regex(CHAR_LITERAL_PATTERN))) {
        operand::type = operand::operand_type::CHAR_LITERAL;
    }
    else if (regex_match(operand_field, std::regex(HEXA_LITERAL_PATTERN))){
        int address = sic_assembler::hex_to_int(operand_field.substr(3, operand_field.length() - 4));
        if (address > operand::MAX_DECIMAL_ADDRESS){
            throw operand_out_of_range();
        }
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

std::string operand::get_address() {
    // calculate operand only once
    if (operand::address != "" || operand::get_type() == operand::operand_type::NONE) {
        return operand::address;
    }

    if (type == operand_type::LABEL) {
        if (!sym_table::get_instance().lookup(name)) {
            throw undefined_symbol();
        } else {
            operand::address = sic_assembler::decimal_to_hex(sym_table::get_instance().get(name),
                                                                 operand::OPERAND_WIDTH);
        }
    } else if (type == operand_type::LABEL_INDEXED) {
        std::size_t found = name.find(",");
        if (!sym_table::get_instance().lookup(name.substr(0, found))) {
            throw undefined_symbol();
        } else {
            operand::address = sic_assembler::decimal_to_hex((1 << 15) 
                            + sym_table::get_instance().get(name), operand::OPERAND_WIDTH);
        }
    } else if (type == operand_type::EXPRESSION){
        expression_evaluator evalutor(name);
        operand::address = evalutor.evaluate();
    } else if(type == operand::operand_type::HEXA_LITERAL || type == operand::operand_type::CHAR_LITERAL
                                        || type == operand::operand_type::WORD_LITERAL) {
        operand::address = sic_assembler::decimal_to_hex(lit_table::get_instance().get(name), operand::OPERAND_WIDTH);
    }
    return operand::address;
}
