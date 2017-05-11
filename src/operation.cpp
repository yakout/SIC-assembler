//
// Created by Ahmed Yakout on 5/10/17.
//

#include <operation.h>
#include <assembler.h>
#include <errors/pass_one/invalid_mnemonic.h>
#include <errors/pass_one/duplicate_symbol.h>
#include <tables/sym_table.h>

operation::operation(std::string instr_str): instruction(instr_str) {
}

void operation::handle() {
	if (has_label()) {
        if (sym_table::get_instance().lookup(get_label())) {
            throw duplicate_symbol();
        } else {
            sym_table::get_instance().insert(get_label(),
                                              sic_assembler::location_counter);
        }
   	}
   	sic_assembler::location_counter += sic_assembler::INSTRUCTION_LENGTH;
}