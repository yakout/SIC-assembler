//
// Created by Ahmed Yakout on 5/2/17.
//


#include "lit_table.h"

lit_table::lit_table() {}

lit_table::~lit_table() {}

lit_table* lit_table::get_instance() {
    if (instance == nullptr) {
        instance = new lit_table();
    }
    return instance;
}

std::string lit_table::get(std::string literal) {
    return table[literal];
}

void lit_table::insert(std::string literal, std::string address) {
    table.insert({literal, address});
}

bool lit_table::lookup(std::string literal) {
    return table.find(literal) != table.end();
}
