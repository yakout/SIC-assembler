//
// Created by Ahmed Yakout on 4/23/17.
//


#include "assembler.h"
#include "mnemonic.h"
#include "op_table.h"

mnemonic::mnemonic(std::string name) {
    if (op_table::get_instance()->get(name).length() == 0) {
        throw "Invalid Mnemonic";
    }
    mnemonic::name = name;
    // todo
}


std::string mnemonic::get_name() {
    return mnemonic::name;
}

std::string mnemonic::get_opcode() {
    return op_table::get_instance()->get(mnemonic::name);
}

bool mnemonic::is_directive() {
    return mnemonic::_is_directive;
}

bool mnemonic::is_extended() {
    return mnemonic::_is_extended;
}

bool mnemonic::operator==(std::string second_mnemonic_name) {
    return sic_assembler::to_lower(name) == sic_assembler::to_lower(second_mnemonic_name);
}

