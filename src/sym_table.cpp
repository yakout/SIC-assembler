//
// Created by Ahmed Yakout on 5/1/17.
//



#include "sym_table.h"
#include "iostream"

bool sym_table::lookup(std::string label) {
    return table.find(label) != table.end();
}

void sym_table::insert(std::string label) {
    table.insert({label});
}

std::string sym_table::get(std::string label) {
    return table[label];
}
