//
// Created by Ahmed Yakout on 5/1/17.
//

#include <assembler.h>
#include <file_reader.h>
#include <pass_one.h>
#include <sym_table.h>
#include <op_table.h>


pass_one::pass_one(file_reader *_reader, std::string _path, std::string _file_name) {
    pass_one::path = _path;
    pass_one::file_name = _file_name;
    pass_one::reader = _reader;
}

void pass_one::pass() {
    bool pass_one_ended = false;
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
    listing_file << "--------------------------------------------------------------------------------------------------------------------\n";

    while (next_instruction == nullptr) {
        try {
            next_instruction = reader->get_next_instruction();
        } catch (const char* e) {
            // we use reader->get_buffer() not instruction->get_full_instruction() because this later method my return nullptr causing
            // segmentation fault
            std::string err_msg = std::string(e);
            listing_file << std::setw(8) << "" << std::left << std::setw(70) << reader->get_buffer() << err_msg << "\n";
        }
    }

    if (*next_instruction->get_mnemonic() == "start") {
        sic_assembler::program_name = next_instruction->get_label();
        sic_assembler::starting_address = sic_assembler::hex_to_int(next_instruction->get_operand()->get_name());
        sic_assembler::location_counter = sic_assembler::starting_address;
        sym_table::get_instance().insert(next_instruction->get_label(), sic_assembler::location_counter);
        next_instruction->set_location(sic_assembler::decimal_to_hex(sic_assembler::location_counter, 4)); // todo remove magic numbers
        listing_file << next_instruction->get_location() << "    " << next_instruction->get_full_instruction() << "\n";
        intermediate_file << next_instruction->get_location() << "    " << next_instruction->get_full_instruction() << "\n";
    } else {
        listing_file << std::setw(8) << "" << std::left << std::setw(70) << reader->get_buffer() << "error: no START directive found" << "\n";
    }


    bool error_flag;
    while(reader->has_next_instruction()) {
        error_flag = false;
//        std::cout << "location counter = " << sic_assembler::decimal_to_hex(sic_assembler::location_counter) << std::endl;
        // if (pass_one_ended) {
        //     throw "error: invalid statements after end directive statement";
        // }
        next_instruction = nullptr;
        while (next_instruction == nullptr) {
        try {
            next_instruction = reader->get_next_instruction();
            next_instruction->set_location(sic_assembler::decimal_to_hex(sic_assembler::location_counter, 4)); // todo remove magic numbers
            intermediate_file << next_instruction->get_location() << "    " << next_instruction->get_full_instruction() << "\n";
        } catch (const char* e) {
            std::string err_msg = std::string(e);
            listing_file << std::setw(8) << "" << std::left << std::setw(70)
                         << reader->get_buffer() << err_msg << "\n";
            // continue;
        }
        }

        if (*next_instruction->get_mnemonic() == "end") {
            pass_one_ended = true;
            break;
        } else if (*next_instruction->get_mnemonic() == "start") {
            listing_file << next_instruction->get_location() << std::setw(4) << "" << std::left << std::setw(70) 
                         << next_instruction->get_full_instruction() 
                         << "error: duplicate start directive statements" << "\n";
            error_flag = true;
        }

        if (next_instruction->has_label()) {
            if (sym_table::get_instance().lookup(next_instruction->get_label())) {
                listing_file << next_instruction->get_location() << std::setw(4) << "" << std::left << std::setw(70) << next_instruction->get_full_instruction()
                             << "error: duplicate symbols" << "\n";
                error_flag = true;
            } else {
                sym_table::get_instance().insert(next_instruction->get_label(),
                                                  sic_assembler::location_counter);
            }
        }

        if (op_table::get_instance().lookup(next_instruction->get_mnemonic()->get_name())) {
            sic_assembler::location_counter += sic_assembler::INSTRUCTION_LENGTH;
        } else if (*next_instruction->get_mnemonic() == "word") {
            // handle array
            if (next_instruction->get_operand()->get_type() == operand::operand_type::DECIMAL_ARRAY) {
                std::string str = next_instruction->get_operand()->get_name();
                sic_assembler::location_counter += sic_assembler::INSTRUCTION_LENGTH 
                                                 * (std::count(str.begin(), str.end(), ',') + 1);
            } else {
                sic_assembler::location_counter += sic_assembler::INSTRUCTION_LENGTH;
            }
        } else if (*next_instruction->get_mnemonic() == "resw") {
            sic_assembler::location_counter += sic_assembler::INSTRUCTION_LENGTH
                                               * std::stoi(next_instruction->get_operand()->get_name());
        } else if (*next_instruction->get_mnemonic() == "resb") {
            sic_assembler::location_counter += stoi(next_instruction->get_operand()->get_name());
        } else if (*next_instruction->get_mnemonic() == "byte") {
            sic_assembler::location_counter += next_instruction->get_operand()->get_length();
//            } else if (*next_instruction->get_mnemonic() == "ORG") {
//                // handle ORG todo: phase 2
//                // update the value of location counter and add the old one to temp value
//                sic_assembler::location_counter_old = sic_assembler::location_counter;
//                // todo should evaluate the expression first
//                sic_assembler::location_counter = stoi(next_instruction->get_operand()->get_name());
//            } else if (*next_instruction->get_mnemonic() == "equ") {
//                // handle EUQ todo: phase 2
//            } else if (*next_instruction->get_mnemonic() == "ltorg") {
//                // handle LTORG todo: phase 2
        } else {
            std::string err_msg = "error: invalid operation code";
            listing_file << next_instruction->get_location() << std::setw(4) << ""  << std::left << std::setw(70) 
                         << next_instruction->get_full_instruction() << err_msg << "\n";
            error_flag = true;
        }
        if (!error_flag) {
            listing_file << next_instruction->get_location() << "    " << next_instruction->get_full_instruction() << "\n";
        }
    }

    if (!pass_one_ended) {
        std::string err_msg = "error: no END directive found";
        listing_file << std::setw(8) << "" << std::left << std::setw(70) << reader->get_buffer() << err_msg << "\n";
    }

    sic_assembler::program_length = sic_assembler::location_counter - sic_assembler::starting_address;

    listing_file << "\n\n>>   *****************************************************\n";
    listing_file << ">>    E N D     O F     P A S S  I \n";
    listing_file << ">>   *****************************************************\n";

    // sym_table::get_instance().print_table();
    sym_table::get_instance().write_table(listing_file);

    listing_file << ">>   *****************************************************\n";
    listing_file.close();
    intermediate_file.close();
}
