//
// Created by Ahmed Yakout on 5/1/17.
//


#include "sym_table.h"
#include "assembler.h"

sym_table::sym_table() {

}

sym_table& sym_table::get_instance() {
    static sym_table instance;
    return instance;
}

bool sym_table::lookup(std::string label) {
    return table.find(label) != table.end();
}

void sym_table::insert(std::string label, int loc_cntr) {
    table.insert({label, loc_cntr});
}

int sym_table::get(std::string label) {
    return table[label];
}

void sym_table::print_table() {
    std::cout << std::endl << "   S Y M B O L     T A B L E" << std::endl;
    for (auto it : table) {
        std::cout << it.first << "      "  << sic_assembler::decimal_to_hex(it.second) << std::endl;
    }
}

void sym_table::write_table(std::ofstream& listing_file) {
    listing_file << ">>    S Y M B O L     T A B L E   (values in hexadecimal)\n\n";
    listing_file << "        name         value     \n";
    listing_file << "        -----------------------\n";
    for (auto it : table) {
        listing_file << std::setw(8) << "" << std::left << std::setw(13) << it.first 
                     << sic_assembler::decimal_to_hex(it.second) << "\n\n"; // todo: adjust spaces
    }
}
