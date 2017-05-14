//
// Created by Ahmed Yakout on 5/1/17.
//

#include <tables/sym_table.h>
#include <tables/op_table.h>
#include <pass_two.h>
#include <file_handlers/object_program_writter.h>
#include <assembler.h>
#include <errors/pass_two/pass_two_error.h>
#include <errors/pass_two/undefined_symbol.h>
#include <null_instruction.h>

pass_two::pass_two(std::unique_ptr<intermediate_file_reader> _reader, std::string _path,
                                        std::string _file_name): path(_path),
                                        file_name(_file_name), reader(std::move(_reader)) {
}

void pass_two::pass() {
    object_program_writter writer(path, file_name);
    std::ofstream listing_file;
    std::string listing_file_path = path + file_name + "_listing.txt";
    listing_file.open(listing_file_path, std::ios_base::app);
    if (!listing_file.is_open()) {
        throw "failed to open file";
    }

    listing_file << ">>    S T A R T     O F     P A S S  II \n";
    listing_file << ">>   *****************************************************\n\n";
    listing_file << ">>   A s s e m b l e d    p r o g r a m     l i s t i n g\n\n";
    listing_file << "LC      " << std::left << std::setw(70) << "Source Statement" << "Object Code         Error\n";
    listing_file << std::setfill('-') << std::setw(110) << "" << "\n";
    listing_file << std::setfill(' ');

    instruction* next_instruction = nullptr;
    next_instruction = reader->get_next_instruction();

    if (next_instruction != nullptr && *next_instruction->get_mnemonic() == "start") {
        writer.write_header_record();
        listing_file << std::left << std::setw(78) << next_instruction->get_full_instruction() 
                     << std::setw(6) << next_instruction->get_object_code() << "\n";
        delete next_instruction;
    }

    while(reader->has_next_instruction()) {
        next_instruction = reader->get_next_instruction();

        if (*next_instruction->get_mnemonic() == "end") {
            // check if end statement has a valid label
            if (next_instruction->has_operand() && next_instruction->get_operand()->get_type() 
                                                    == operand::operand_type::LABEL) {
                if (!sym_table::get_instance().lookup(next_instruction->get_operand()->get_name())) {
                    delete next_instruction;
                    throw undefined_symbol();
                }
            }
            listing_file << std::left << std::setw(78) << next_instruction->get_full_instruction() 
                     << std::setw(6) << next_instruction->get_object_code() << "\n";
            break;
        }

        std::cout << next_instruction->get_object_code() << std::endl;

        listing_file << std::left << std::setw(78) << next_instruction->get_full_instruction() 
                     << std::setw(6) << next_instruction->get_object_code() << "\n";
        writer.add_to_text_record(next_instruction);

        if (reader->has_next_instruction()) {
            // delete current instruction and continue to fetch new one.
            delete next_instruction;
        }
    }
    
    if (next_instruction->has_operand()) {
        // use operand label address
        writer.write_end_record(sym_table::get_instance().get(next_instruction->get_operand()->get_name()));
    } else {
        // use the default starting_address for the program
        writer.write_end_record(sic_assembler::starting_address);
    }
    delete next_instruction;

    listing_file << "\n>>    s u c c e s s f u l    a s s e m b l y\n";
    listing_file.close();
}
