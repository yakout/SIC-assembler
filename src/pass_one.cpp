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
    bool pass_one_ended = false;
    instruction* next_instruction = reader->get_next_instruction();
    int line_number = 0;

    while (next_instruction->is_comment()) {
        next_instruction = reader->get_next_instruction();
    }
    if (*next_instruction->get_mnemonic() == "START") {
        sic_assembler::starting_address = sic_assembler::hex_to_int(next_instruction->get_operand()->get_name());
    } else {
        throw "error: no START directive found";
    }

    while(reader->has_next_instruction()) {
        next_instruction = reader->get_next_instruction();
        if (*next_instruction->get_mnemonic() == "END") {
            pass_one_ended = true;
            break;
        }
        if (next_instruction->is_comment()) {
            continue;
        }
        if (next_instruction->has_label()) {
            if (sym_table::get_instance()->lookup(next_instruction->get_label())) {
                throw "error: duplicate symbols";
            } else {
                sym_table::get_instance()->insert(next_instruction->get_label(),
                                                 sic_assembler::location_counter);
            }
            if (op_table::get_instance()->lookup(next_instruction->get_mnemonic()->get_name())) {
            } else if (*next_instruction->get_mnemonic() == "WORD") {
                sic_assembler::location_counter += sic_assembler::INSTRUCTION_LENGTH;
            } else if (*next_instruction->get_mnemonic() == "RESW") {
                sic_assembler::location_counter += sic_assembler::INSTRUCTION_LENGTH
                                                   * std::stoi(next_instruction->get_operand()->get_name());
            } else if (*next_instruction->get_mnemonic() == "RESB") {
                sic_assembler::location_counter += stoi(next_instruction->get_operand()->get_name());
            } else if (*next_instruction->get_mnemonic() == "BYTE") {
                sic_assembler::location_counter += next_instruction->get_operand()->get_length();
            } else if (*next_instruction->get_mnemonic() == "ORG") {
                // handle ORG
                // update the value of location counter and add the old one to temp value
                sic_assembler::location_counter_old = sic_assembler::location_counter;
                // todo should evaluate the expression first
                sic_assembler::location_counter = stoi(next_instruction->get_operand()->get_name());
            } else if (*next_instruction->get_mnemonic() == "EQU") {
                // handle EUQ
            } else if (*next_instruction->get_mnemonic() == "LTORG") {
                // handle LTORG
            } else {
                throw "error: invalid operation code";
            }
        }
    }
    if (!pass_one_ended) {
        throw "error: no END directive found";
    }
}
