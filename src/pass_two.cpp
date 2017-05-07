//
// Created by Ahmed Yakout on 5/1/17.
//



#include <sym_table.h>
#include <op_table.h>
#include <pass_two.h>
#include <object_program_writter.h>
#include <assembler.h>

pass_two::pass_two(file_reader *_reader, std::string _path, std::string _file_name) {
    pass_two::path = _path;
    pass_two::file_name = _file_name;
    reader = _reader;
}

void pass_two::pass() {
    object_program_writter writer(path, file_name); //"./", "tests/valid_test1"
    std::ofstream listing_file;
    std::string listing_file_path = path + file_name + "_listing.txt";
    listing_file.open(listing_file_path, std::ios_base::app);
    if (!listing_file.is_open()) {
        throw "failed to open file";
    }

    listing_file << ">>    S T A R T     O F     P A S S  II \n";
    listing_file << ">>   *****************************************************\n\n";
    listing_file << ">>   A s s e m b l e d    p r o g r a m     l i s t i n g\n\n";
    listing_file << " Object Code         Source Statement\n";
    listing_file << "---------------------------------------------\n";

    instruction* next_instruction = nullptr;
    try {
        next_instruction = reader->get_next_instruction();
    } catch (const char* e) {
        std::string msg = std::string(e) + " at first instruction";
        throw std::string(msg);
    }

    if (*next_instruction->get_mnemonic() == "start") {
        writer.write_header_record();
        listing_file << std::setw(21) << ""  << next_instruction->get_full_instruction() << "\n";
    }
    while(reader->has_next_instruction()) {
        try {
            next_instruction = reader->get_next_instruction();
        } catch (const char* e) {
            std::string msg = std::string(e) + " at line number " + std::to_string(next_instruction->get_line_number());
            throw std::string(msg);
        }

        if (*next_instruction->get_mnemonic() == "end") {
            // check if end statement has a valid label
            if (next_instruction->has_operand() && next_instruction->get_operand()->get_type() 
                                                    == operand::operand_type::LABEL) {
                if (!sym_table::get_instance().lookup(next_instruction->get_operand()->get_name())) {
                    throw "undefined symbol in end Statement";
                }
            }
            break;
        }
        if (!op_table::get_instance().lookup(next_instruction->get_mnemonic()->get_name()) 
                    && *next_instruction->get_mnemonic() != "byte"
                    && *next_instruction->get_mnemonic() != "word") {
                continue;
        }
        try {
            std::cout << next_instruction->get_opcode() << std::endl;
        } catch (const char* e) {
            throw std::string(e) + "at line " + std::to_string(next_instruction->get_line_number());
        }

        listing_file << std::setw(6) << next_instruction->get_opcode() << std::setw(15) << "" 
                                     << next_instruction->get_full_instruction() << "\n";
        writer.add_to_text_record(next_instruction);
    }
    writer.write_end_record(sic_assembler::starting_address);
    listing_file << "\n>>    s u c c e s s f u l    a s s e m b l y\n";
    listing_file.close();
}
