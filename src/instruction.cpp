//
// Created by Ahmed Yakout on 4/23/17.
//

#include <instruction.h>

bool instruction::has_label() {
    return false;
}

void instruction::set_label(string) {

}

void instruction::set_mnemonic(mnemonic) {

}

void instruction::set_operand(operand) {

}

void instruction::set_comment(string) {

}

string instruction::get_label() {
    return std::string();
}

mnemonic instruction::get_mnemonic() {
    return mnemonic(__1::basic_string<char, char_traits<char>, allocator<char>>(), false, false);
}

operand instruction::get_operand() {
    return operand();
}

string instruction::get_comment() {
    return std::string();
}


