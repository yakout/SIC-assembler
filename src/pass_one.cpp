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
    using namespace sic_assembler;
    bool pass_one_ended = false;
    instruction* next_instruction = reader->get_next_instruction();

    if (*next_instruction->get_mnemonic() == "START") {
        starting_address = hex_to_int(next_instruction->get_operand()->get_name());
    } else {
        // todo throw error
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
                // todo throw error
            } else {
                sym_table::get_instance()->insert(next_instruction->get_label(),
                                                 sic_assembler::location_counter);
            }
            if (op_table::get_instance()->lookup(next_instruction->get_mnemonic()->get_name())) {
            } else if (*next_instruction->get_mnemonic() == "WORD") {
            } else if (*next_instruction->get_mnemonic() == "RESW") {
                sic_assembler::INSTRUCTION_LENGTH * std::stoi(next_instruction->get_operand()->get_name());
            } else if (*next_instruction->get_mnemonic() == "RESB") {
                stoi(next_instruction->get_operand()->get_name());
            } else if (*next_instruction->get_mnemonic() == "BYTE") {
                next_instruction->get_operand()->get_length();
            } else {
                // todo throw error: invalid operation code
            }
        }
    }
    if (!pass_one_ended) {
//        todo throw error : no END directive found
    }
}
