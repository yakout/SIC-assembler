//
// Created by Ahmed Yakout on 5/1/17.
//

#include <assembler.h>
#include "pass_one.h"
#include "instruction.h"
#include "sym_table.h"
#include "op_table.h"


pass_one::pass_one() {
    // todo // initalize the input reader
}

void pass_one::pass() {
    using namespace assembler;
    bool pass_one_ended = false;
    instruction next_instruction;// = input_reader.next();
    if (next_instruction.get_mnemonic() == "START") {
        starting_address = hex_to_int(next_instruction.get_operand().get_name());
        location_counter = starting_address;
    }
    // todo throw error

    while(input_reader.has_next()) {
        next_instruction = input_reader.next();
        if (next_instruction.get_mnemonic() == "END") {
            pass_one_ended = true;
        }
        if (next_instruction.is_comment()) {
            continue;
        }
        if (next_instruction.has_label()) {
            if (sym_table::get_instance().lookup(next_instruction.get_label())) {
                // todo throw error
            } else {
                sym_table::get_instance().insert(next_instruction.get_label());
            }
            if (op_table::getInstance().lookup(next_instruction.get_mnemonic().get_name())) {
                location_counter += 3;
            } else if (next_instruction.get_mnemonic() == "WORD") {
                location_counter += 3;
            } else if (next_instruction.get_mnemonic() == "RESW") {
                location_counter += 3 * strtod(next_instruction.get_operand().get_name());
            } else if (next_instruction.get_mnemonic() == "RESB") {
                location_counter +=  stoi(next_instruction.get_operand().get_name());
            } else if (next_instruction.get_mnemonic() == "BYTE") {
                location_counter += next_instruction.get_operand().get_length();
            } else {
                // todo throw error: invalid operation code
            }
        }
    }
    program_length = location_counter - starting_address;
}
