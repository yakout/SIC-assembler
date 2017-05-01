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

std::string op_table::get(std::string key) {
    return table[key];
}

bool op_table::lookup(std::string label) {
    return table.find(label) != table.end();
}

void op_table::init_table() {
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

    table.insert({"add", "18"});
    table.insert({"and", "40"});
    table.insert({"comp", "28"});
    table.insert({"div", "24"});
    table.insert({"j", "3C"});
    table.insert({"jgt", "34"});
    table.insert({"jlt", "38"});
    table.insert({"jsub", "48"});
    table.insert({"lda", "00"});
    table.insert({"ldch", "50"});
    table.insert({"ldx", "04"});
    table.insert({"mul", "20"});
    table.insert({"or", "44"});
    table.insert({"rd", "D8"});
    table.insert({"rsub", "4C"});
    table.insert({"sta", "0C"});
    table.insert({"stch", "54"});
    table.insert({"stl", "D4"});
    table.insert({"stx", "10"});
    table.insert({"sub", "1C"});
    table.insert({"td", "F8"});
    table.insert({"tix", "2C"});
    table.insert({"wd", "DC"});
}
