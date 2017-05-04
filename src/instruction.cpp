//
// Created by Ahmed Yakout on 4/23/17.
//

#include "instruction.h"
#include "regex_patterns.h"
#include <regex>
#include <assembler.h>

instruction::instruction() {
    instruction::_mnemonic = nullptr;
    instruction::_operand = nullptr;
    instruction::label.clear();
    instruction::comment.clear();
}

instruction::~instruction() {
}

bool instruction::has_label() {
    return instruction::label.length() != 0;
}

std::string instruction::get_opcode() {
    if (instruction::has_operand()) {
        return instruction::_mnemonic->get_opcode() + instruction::_operand->get_opcode();
    }
    else {
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
    return instruction::_operand != nullptr;
}

void instruction::set_operand(operand *_operand) {
    instruction::_operand = _operand;
}

void instruction::set_comment(std::string comment) {
    instruction::comment = comment;
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
    return instruction::comment;
}



