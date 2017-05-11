//
// Created by Ahmed Yakout on 5/2/17.
//


#include <tables/lit_table.h>
#include <assembler.h>
#include <iostream>

lit_table::lit_table() {
    
}

lit_table& lit_table::get_instance() {
    static lit_table instance;
    return instance;
}

int lit_table::get(std::string literal) {
    return table[literal];
}

void lit_table::insert(std::string literal, int address) {
    table.insert({literal, address});
}

bool lit_table::lookup(std::string literal) {
    return table.find(literal) != table.end();
}

void lit_table::insert(std::string literal) {
    if (!lookup(literal)) {
        unassigned_literals.push_back(literal);
        insert(literal, 0);
    }
}

std::vector<std::string> lit_table::get_unassigned_literals() {
    return unassigned_literals;
}

void lit_table::set_ofstreams(std::ofstream* _listing_file, std::ofstream* _intermediate_file) {
    listing_file = _listing_file;
    intermediate_file = _intermediate_file;
}

void lit_table::append_unassgined_literals() {
    for (std::string unassigned_literal : unassigned_literals) {
        std::string loc = sic_assembler::decimal_to_hex(sic_assembler::location_counter);
        *listing_file << loc << "    *        " << unassigned_literal << "\n";
        *intermediate_file << loc << "    *        " << unassigned_literal << "\n";
        sic_assembler::location_counter += sic_assembler::INSTRUCTION_LENGTH;
    }
}

void lit_table::write_table(std::ofstream& listing_file) {
    listing_file << ">>    L I T E R A L     T A B L E   (values in hexadecimal)\n\n";
    listing_file << "        name         value     \n";
    listing_file << "        -----------------------\n";
    for (auto it : table) {
        listing_file << std::setw(8) << "" << std::left << std::setw(13) << it.first 
                     << sic_assembler::decimal_to_hex(it.second) << "\n\n"; // todo: adjust spaces
    }
}
