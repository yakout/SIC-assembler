//
// Created by Ahmed Yakout on 5/1/17.
//


#include "sym_table.h"
#include "assembler.h"

bool sym_table::lookup(std::string label) {
    return table.find(label) != table.end();
}

void sym_table::insert(std::string label, int loc_cntr) {
    table.insert({label, loc_cntr});
}

int sym_table::get(std::string label) {
    return table[label];
}

sym_table::sym_table(): table() {

}

sym_table::~sym_table() {

}

void sym_table::print_table() {
    std::cout << std::endl << "   S Y M B O L     T A B L E" << std::endl;
    for (auto it : table) {
        std::cout << it.first << "      "  << sic_assembler::decimal_to_hex(it.second) << std::endl;
    }
}
