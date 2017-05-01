//
// Created by Ahmed Yakout on 5/1/17.
//



#include "sym_table.h"
#include "op_table.h"
#include "pass_two.h"
#include "object_program_writter.h"
#include "assembler.h"

pass_two::pass_two(file_reader *_reader) {
    reader = _reader;
}

void pass_two::pass() {
    bool pass_two_ended = false;
    reader->get_next_instruction();
    object_program_writter writter;

    instruction next_instruction = *reader->get_next_instruction();
    if (*next_instruction.get_mnemonic() == "START") {
        writter.write_header_record(next_instruction.get_label(),
                                     std::to_string(sic_assembler::starting_address),
                                     to_string(sic_assembler::program_length));
    } else {
        // todo throw error
    }

    while(reader->has_next_instruction()) {
        next_instruction = *reader->get_next_instruction();
        if (*next_instruction.get_mnemonic() == "END") {
            pass_two_ended = true;
            break;
        }
        if (next_instruction.is_comment()) {
            continue;
        }
        if (op_table::get_instance()->lookup(next_instruction.get_mnemonic()->get_name())) {
            if (next_instruction.get_operand()->.get_type() == operand::operand_type::LABEL) {
                if (sym_table::get_instance()->lookup(next_instruction.get_operand()->get_name())) {
                    //
                }
            }
        } else if (*next_instruction.get_mnemonic() == "WORD"
                || *next_instruction.get_mnemonic() == "BYTE") {
            // next_instruction.get_operand()
            // convert constant to object code
            // next_instruction.set_object_code()
        }

    }
}
