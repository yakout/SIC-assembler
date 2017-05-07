//
// Created by Ahmed Yakout on 4/23/17.
//

#include "instruction.h"
#include "regex_patterns.h"
#include <regex>
#include <assembler.h>

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
    if (*get_mnemonic() == "word" && instruction::has_operand() 
                        && instruction::_operand->get_type() == operand::operand_type::DECIMAL_ARRAY) {
        std::string temp = "";
        for (int i = 0; i < instruction::_operand->get_opcode().length(); i++){
            temp += instruction::_operand->get_opcode()[i];
            if (_operand->get_opcode()[i] == ','){
                temp += sic_assembler::decimal_to_hex(0, operand::OPCODE_WIDTH);
            }
        }
        return temp;
    } else if (*get_mnemonic() == "word" && instruction::has_operand()) {
        return sic_assembler::decimal_to_hex(0, operand::OPCODE_WIDTH) + instruction::_operand->get_opcode();
    } else if (*get_mnemonic() == "resw" || *get_mnemonic() == "resb") {
        return "";
    } else if (instruction::has_operand()) {
        return instruction::_mnemonic->get_opcode() + instruction::_operand->get_opcode();
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
        throw "Invalid LABEL field";
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
        throw "Invalid operand type for mnemonic";
    }
    instruction::_operand = _operand;
}

void instruction::set_comment(std::string _comment) {
    instruction::_comment = _comment;
}

void instruction::set_location(std::string _location) {
    instruction::_location = _location;
}

void instruction::set_line_number(int _line_number) {
    instruction::_line_number = _line_number;
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

int instruction::get_line_number() {
    return instruction::_line_number;
}

std::string instruction::get_full_instruction() {
    return instruction::full_instruction;
}