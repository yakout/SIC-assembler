//
// Created by Ahmed Yakout on 5/2/17.
//


#include "lit_table.h"

lit_table *lit_table::instance = nullptr;

lit_table::lit_table(): table(), unassigned_literals() {
}

lit_table::~lit_table() {

}

lit_table* lit_table::get_instance() {
    if (lit_table::instance == nullptr) {
        lit_table::instance = new lit_table();
    }
    return lit_table::instance;
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

void lit_table::insert(std::string literal) {
    if (!lookup(literal)) {
        unassigned_literals.push_back(literal);
        insert(literal, nullptr);
    }
}

std::vector<std::string> lit_table::get_unassigned_literals() {
    return unassigned_literals;
}
