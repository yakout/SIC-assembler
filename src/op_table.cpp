//
// Created by Ahmed Yakout on 4/23/17.
//

#include "op_table.h"

op_table *op_table::instance = nullptr;

op_table::op_table() {
    init_table();
}

op_table *op_table::get_instance() {
    if (op_table::instance == nullptr) {
        op_table::instance = new op_table();
    }
    return op_table::instance;
}

string op_table::get(string key) {
    return table[key];
}

bool op_table::lookup(string label) {
    return table.find(label) != table.end();
}

void op_table::init_table() {
//    todo add the hex value not the decimal

//    table.insert({"add", 24});
//    table.insert({"and", 64});
//    table.insert({"comp", 40});
//    table.insert({"div", 36});
//    table.insert({"j", 60});
//    table.insert({"jgt", 48});
//    table.insert({"jlt", 56});
//    table.insert({"jsub", 72});
//    table.insert({"lda", 0});
//    table.insert({"ldch", 80});
//    table.insert({"ldx", 4});
//    table.insert({"mul", 32});
//    table.insert({"or", 68});
//    table.insert({"rd", 216});
//    table.insert({"rsub", 76});
//    table.insert({"sta", 12});
//    table.insert({"stch", 84});
//    table.insert({"stl", 20});
//    table.insert({"stx", 16});
//    table.insert({"sub", 28});
//    table.insert({"td", 224});
//    table.insert({"tix", 44});
//    table.insert({"wd", 220});
}
