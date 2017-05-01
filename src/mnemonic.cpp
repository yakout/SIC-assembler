//
// Created by Ahmed Yakout on 4/23/17.
//


#include "mnemonic.h"
#include "op_table.h"

mnemonic::mnemonic(string name) {
    if (op_table::get_instance()->get(name).length() == 0) {
        throw "Invalid Mnemonic";
    }
    mnemonic::name = name;
    // todo
}


string mnemonic::get_name() {
    return mnemonic::name;
}

string mnemonic::get_opcode() {
    return op_table::get_instance()->get(mnemonic::name);
}

bool mnemonic::is_directive() {
    return mnemonic::_is_directive;
}

bool mnemonic::is_extended() {
    return mnemonic::_is_extended;
}

