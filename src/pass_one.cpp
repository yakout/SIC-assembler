//
// Created by Ahmed Yakout on 5/1/17.
//

#include "assembler.h"
#include "file_reader.h"
#include "pass_one.h"
#include "sym_table.h"
#include "op_table.h"


pass_one::pass_one(file_reader *_reader) {
    reader = _reader;
}

void pass_one::pass() {
    int line_number = 0;
    bool pass_one_ended = false;
    instruction *next_instruction = nullptr;
    try {
        line_number++;
        next_instruction = reader->get_next_instruction();
    } catch (const char* e) {
        std::string msg = std::string(e) + " at line number " + std::to_string(line_number);
        throw std::string(msg);
    }

    if (*next_instruction->get_mnemonic() == "start") {
        sic_assembler::starting_address = sic_assembler::hex_to_int(next_instruction->get_operand()->get_name());
        sic_assembler::location_counter = sic_assembler::starting_address;
    } else {
        throw "error: no START directive found";
    }

    while(reader->has_next_instruction()) {
//        std::cout << "location counter = " << sic_assembler::decimal_to_hex(sic_assembler::location_counter) << std::endl;
        try {
            line_number++;
            next_instruction = reader->get_next_instruction();
            next_instruction->set_location(sic_assembler::decimal_to_hex(sic_assembler::location_counter));
        } catch (const char* e) {
            std::string msg = std::string(e) + " at line number " + std::to_string(line_number);
            throw std::string(msg);
        }
        if (*next_instruction->get_mnemonic() == "end") {
            pass_one_ended = true;
            break;
        }
        if (next_instruction->has_label()) {
            if (sym_table::get_instance()->lookup(next_instruction->get_label())) {
                throw "error: duplicate symbols";
            } else {
                sym_table::get_instance()->insert(next_instruction->get_label(),
                                                  sic_assembler::location_counter);
            }
        }
//        std::cout << next_instruction->get_mnemonic()->get_name() << "\n";
        if (op_table::get_instance()->lookup(next_instruction->get_mnemonic()->get_name())) {
            sic_assembler::location_counter += sic_assembler::INSTRUCTION_LENGTH;
        } else if (*next_instruction->get_mnemonic() == "word") {
            sic_assembler::location_counter += sic_assembler::INSTRUCTION_LENGTH;
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
            throw "error: invalid operation code";
        }
    }
    if (!pass_one_ended) {
        throw "error: no END directive found";
    }
    sic_assembler::program_length = sic_assembler::location_counter - sic_assembler::starting_address;
    sym_table::get_instance()->print_table();
}
