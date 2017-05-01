//
// Created by Ahmed Yakout on 4/23/17.
//

#include "instruction.h"
#include "regex_patterns.h"
#include "mnemonic.h"
#include <regex>

instruction::instruction() {
    instruction::_mnemonic = nullptr;
    instruction::_operand = nullptr;
    instruction::label.clear();
    instruction::comment.clear();
}

bool instruction::has_label() {
    return instruction::label.length() != 0;
}

void instruction::set_label(string label) {
    if (regex_match(label, regex(EMPTY_STRING_PATTERN))) {
        instruction::label.clear();
    } else if (regex_match(label, regex(LABEL_PATTERN))) {
        instruction::label = label;
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

void instruction::set_comment(string comment) {
    instruction::comment = comment;
}

string instruction::get_label() {
    return instruction::label;
}

mnemonic *instruction::get_mnemonic() {
    return instruction::_mnemonic;
}

operand *instruction::get_operand() {
    return instruction::_operand;
}

string instruction::get_comment() {
    return instruction::comment;
}

bool instruction::is_comment() {
    return full_instr[0] == '.';
}


