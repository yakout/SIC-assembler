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
    object_program_writter writer("./", "tests/valid_test1");

    instruction* next_instruction = reader->get_next_instruction();
    if (*next_instruction->get_mnemonic() == "start") {
        writer.write_header_record(next_instruction->get_label());
    }
    while(reader->has_next_instruction()) {
        next_instruction = reader->get_next_instruction();
        if (*next_instruction->get_mnemonic() == "end") {
            break;
        }
        if (op_table::get_instance()->lookup(next_instruction->get_mnemonic()->get_name())) {
            if (next_instruction->has_operand()
                && next_instruction->get_operand()->get_type() == operand::operand_type::LABEL) {
                if (sym_table::get_instance()->lookup(next_instruction->get_operand()->get_name())) {
                    // we set the operand address as the symbol value from sym_table
                } else {
                    // we set the operand address = 0
                    // set error flag
                }
            }
        } else { // directive
            if (*next_instruction->get_mnemonic() != "byte"
                    && *next_instruction->get_mnemonic() != "word") {
                continue;
            }
        }
        std::cout << next_instruction->get_opcode() << std::endl;
        writer.add_to_text_record(next_instruction);
    }
    writer.write_end_record(sic_assembler::starting_address);
}
