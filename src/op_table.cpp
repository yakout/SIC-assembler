//
// Created by Ahmed Yakout on 4/23/17.
//


#include "op_table.h"
using namespace assembler;


op_table::op_table() {
    optab["add"] = "18";
    optab["lda"] = "00";
    // todo
}

op_table* op_table::getInstance() {
    if (op_table::instance == nullptr) {
        instance = new op_table();
    }
    return instance;
}

string op_table::get(string key) {
    return optab[key];
}
