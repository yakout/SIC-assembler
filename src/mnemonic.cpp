//
// Created by Ahmed Yakout on 4/23/17.
//


#include <mnemonic.h>
#include "op_table.h"

string mnemonic::get_name() {
    return mnemonic::name;
}

string mnemonic::get_opcode() {
    return op_table::getInstance().get(mnemonic::get_name());
//    return nullptr;
}

bool mnemonic::is_directive() {
    return mnemonic::_is_directive;
}

bool mnemonic::is_extended() {
    return mnemonic::_is_extended;
}

