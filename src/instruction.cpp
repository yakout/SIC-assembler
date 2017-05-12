//
// Created by Ahmed Yakout on 4/23/17.
//

#include <instruction.h>
#include <regex_patterns.h>
#include <regex>
#include <assembler.h>
#include <errors/pass_one/invalid_label.h>
#include <errors/pass_one/invalid_combination.h>

instruction::instruction(std::string buffer): full_instruction(buffer) {
    instruction::_mnemonic = nullptr;
    instruction::_operand = nullptr;
    instruction::label.clear();
    instruction::_comment.clear();
}

instruction::~instruction() {
    delete _mnemonic;
    delete _operand;
}

bool instruction::has_label() {
    return instruction::label.length() != 0;
}

std::string instruction::get_opcode() {
    if (*get_mnemonic() == "word" && instruction::has_operand()) {
        if (instruction::_operand->get_type() == operand::operand_type::DECIMAL_ARRAY) {
            // handle array: WORD   1,2,3
            std::string temp = "00";
            for (int i = 0; i < instruction::_operand->get_address().length(); i++){
                temp += instruction::_operand->get_address()[i];
                if (_operand->get_address()[i] == ','){
                    temp += sic_assembler::decimal_to_hex(0, operand::OPCODE_WIDTH);
                }
            }
            return temp;
        } else {
            return sic_assembler::decimal_to_hex(0, operand::OPCODE_WIDTH) + instruction::_operand->get_address();
        }
    } else if (*get_mnemonic() == "resw" || *get_mnemonic() == "resb" || *get_mnemonic() == "start" 
                        || *get_mnemonic() == "end" || *get_mnemonic() == "equ"
                        || *get_mnemonic() == "ltorg" || *get_mnemonic() == "org") {
        return "";
    } else if (*get_mnemonic() == "byte") {
        return instruction::_operand->get_address();
    } else if (instruction::has_operand()) {
        return instruction::_mnemonic->get_opcode() + instruction::_operand->get_address();
    } else {
        return instruction::_mnemonic->get_opcode() + sic_assembler::decimal_to_hex(0, operand::OPERAND_WIDTH);
    }
}

void instruction::set_label(std::string label) {
    if (regex_match(label, std::regex(EMPTY_STRING_PATTERN))) {
        instruction::label.clear();
    } else if (regex_match(label, std::regex(LABEL_PATTERN))) {
        instruction::label = sic_assembler::trim(label);
    } else {
        throw invalid_label();
    }
}

void instruction::set_mnemonic(mnemonic *_mnemonic) {
    instruction::_mnemonic = _mnemonic;
}

bool instruction::has_operand() {
    return instruction::_operand->get_type() != operand::operand_type::NONE;
}

void instruction::set_operand(operand *_operand) {
    if (!instruction::_mnemonic->is_valid_operand(_operand)){
        throw invalid_combination();
    }
    instruction::_operand = _operand;
}

void instruction::set_comment(std::string _comment) {
    instruction::_comment = _comment;
}

void instruction::set_location(std::string _location) {
    instruction::_location = _location;
}

std::string instruction::get_label() {
    return instruction::label;
}

mnemonic* instruction::get_mnemonic() {
    return instruction::_mnemonic;
}

operand* instruction::get_operand() {
    return instruction::_operand;
}

std::string instruction::get_comment() {
    return instruction::_comment;
}

std::string instruction::get_location() {
    return instruction::_location;
}

std::string instruction::get_full_instruction() {
    return instruction::full_instruction;
}