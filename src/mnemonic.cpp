//
// Created by Ahmed Yakout on 4/23/17.
//


#include "assembler.h"
#include "mnemonic.h"
#include "op_table.h"

mnemonic::mnemonic(std::string name) {
    if (!op_table::get_instance()->lookup(name) && sic_assembler::is_directive(name)) {
        throw "Invalid Mnemonic";
    }
    mnemonic::name = sic_assembler::trim(name);
}

std::string mnemonic::get_name() {
    return mnemonic::name;
}

std::string mnemonic::get_opcode() {
    return op_table::get_instance()->get(mnemonic::name);
}

bool mnemonic::is_directive() {
    return sic_assembler::is_directive(name);
}

bool mnemonic::operator==(std::string second_mnemonic_name) {
    return sic_assembler::trim(name) == second_mnemonic_name;
}

bool mnemonic::operator!=(std::string second_mnemonic_name) {
    return !(*this == second_mnemonic_name);
}

