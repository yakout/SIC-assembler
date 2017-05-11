//
// Created by Ahmed Yakout on 5/1/17.
//

#include <assembler.h>
#include <file_handlers/file_reader.h>
#include <pass_one.h>
#include <tables/sym_table.h>
#include <tables/op_table.h>
#include <errors/pass_one/pass_one_error.h>
#include <null_instruction.h>
#include <directives/start_directive.h>

pass_one::pass_one(std::unique_ptr<file_reader> _reader, std::string _path,
                                        std::string _file_name): path(_path),
                                        file_name(_file_name), reader(std::move(_reader)) {
}

void pass_one::pass() {
    bool pass_one_ended = false;
    bool incomplete_assembly = false;
    instruction *next_instruction = nullptr;

    // open intermediate file
    std::ofstream intermediate_file;
    std::string intermediate_file_path = path + file_name + "_intermediate.txt";
    intermediate_file.open(intermediate_file_path);
    if (!intermediate_file.is_open()) {
        throw "failed to open file";
    }

    // open listing file
    std::ofstream listing_file;
    std::string listing_file_path = path + file_name + "_listing.txt";
    listing_file.open(listing_file_path);
    if (!listing_file.is_open()) {
        throw "failed to open file";
    }


    listing_file << ">>    S T A R T     O F     P A S S  I \n";
    listing_file << ">>  Source Program statements with value of LC indicated\n\n";
    listing_file << "LC      Source Statement                                                      Error\n";
    listing_file << std::setfill('-') << std::setw(120) << "" << "\n";
    listing_file << std::setfill(' ');

    try {
        next_instruction = reader->get_next_instruction();
    } catch (const pass_one_error& e) {
        listing_file << std::setw(8) << "" << std::left << std::setw(70) 
                     << reader->get_buffer() << e.what() << "\n";
        listing_file << std::setw(8) << "" << std::left << std::setw(70) 
                     << reader->get_buffer() << "error: no START directive found  in the begining" << "\n";
        incomplete_assembly = true;
    } 

    if (next_instruction == nullptr) {

    } else if (dynamic_cast<null_instruction*>(next_instruction) != nullptr) {
        // file is empty.
        listing_file.close();
        intermediate_file.close();
        return;
    } else if (next_instruction != nullptr) {
        next_instruction->handle();
        if (dynamic_cast<start_directive*>(next_instruction) == nullptr) {
            listing_file << std::setw(8) << "" << std::left << std::setw(70) 
                                         << reader->get_buffer() 
                                         << "error: no START directive found in the begining" << "\n";
        } else {
            next_instruction->set_location(sic_assembler::decimal_to_hex(sic_assembler::location_counter,
                                                                         sic_assembler::LOCATION_LENGTH));
            intermediate_file << next_instruction->get_location() << "    " 
                              << next_instruction->get_full_instruction() << "\n";
            listing_file << next_instruction->get_location() << std::setw(4) << ""  
                             << std::left << std::setw(70) 
                             << next_instruction->get_full_instruction() << "" << "\n";
        }
    }


    while(reader->has_next_instruction()) {
        try {
            next_instruction = reader->get_next_instruction();
        } catch (const pass_one_error& e) {
            listing_file << std::setw(8) << "" << std::left << std::setw(70)
                         << reader->get_buffer() << e.what() << "\n";
            incomplete_assembly = true;
            continue;
        }

        next_instruction->set_location(sic_assembler::decimal_to_hex(sic_assembler::location_counter,
                                                                    sic_assembler::LOCATION_LENGTH));
        intermediate_file << next_instruction->get_location() << "    " 
                          << next_instruction->get_full_instruction() << "\n";

        if (*next_instruction->get_mnemonic() == "end") {
            pass_one_ended = true;
            listing_file << next_instruction->get_location() << "    " 
                         << next_instruction->get_full_instruction() << "\n";
            break;
        }

        try {
            next_instruction->handle();   
            // success
            listing_file << next_instruction->get_location() << "    " 
                         << next_instruction->get_full_instruction() << "\n";
        } catch (const pass_one_error& e) {
            // failure
            listing_file << next_instruction->get_location() << std::setw(4) << ""  
                         << std::left << std::setw(70) 
                         << next_instruction->get_full_instruction() << e.what() << "\n";
            incomplete_assembly = true;
        }

        delete next_instruction;
    }

    if (!pass_one_ended) {
        std::string err_msg = "error: no END directive found";
        listing_file << std::setw(8) << "" << std::left << std::setw(70) << reader->get_buffer() 
                                     << err_msg << "\n";
    }

    sic_assembler::program_length = sic_assembler::location_counter - sic_assembler::starting_address;

    listing_file << "\n\n>>   *****************************************************\n";
    listing_file << ">>    E N D     O F     P A S S  I \n";
    listing_file << ">>   *****************************************************\n";

    // sym_table::get_instance().print_table();
    sym_table::get_instance().write_table(listing_file);

    listing_file << ">>   *****************************************************\n";
    intermediate_file.close();

    if (incomplete_assembly) {
        listing_file << "i n c o m p l e t e      a s s e m b l y\n";
        listing_file.close();
        throw "incomplete assembly";
    }
    listing_file.close();
}
