//
// Created by Ahmed Yakout on 4/23/17.
//

#include "op_table.h"

op_table *op_table::instance = nullptr;

op_table::op_table() {
    optab["add"] = "18";
    optab["lda"] = "00";
    // todo
}

op_table *op_table::get_instance() {
    if (op_table::instance == nullptr) {
        op_table::instance = new op_table();
    }
    return op_table::instance;
}

string op_table::get(string key) {
    return optab[key];
}
