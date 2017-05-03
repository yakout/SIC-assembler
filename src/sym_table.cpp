//
// Created by Ahmed Yakout on 5/1/17.
//


#include "sym_table.h"
#include "assembler.h"

bool sym_table::lookup(std::string label) {
    return table.find(label) != table.end();
}

void sym_table::insert(std::string label, int loc_cntr) {
    table.insert({label, sic_assembler::decimal_to_hex(loc_cntr)});
}

std::string sym_table::get(std::string label) {
    return table[label];
}

sym_table::sym_table(): table() {

}

sym_table::~sym_table() {

}
