//
// Created by Ahmed Yakout on 5/10/17.
//

#include <directives/start_directive.h>
#include <assembler.h>
#include <tables/sym_table.h>
#include <errors/pass_one/duplicate_start_directive.h>

int start_directive::count = 0;

start_directive::start_directive(std::string inst_str): directive(inst_str) {
	start_directive::count++;
}

void start_directive::handle() {
	if (start_directive::count > 1) {
		throw duplicate_start_directive();
	}
    sic_assembler::program_name = get_label();
    sic_assembler::starting_address = sic_assembler::hex_to_int(get_operand()->get_name());
    sic_assembler::location_counter = sic_assembler::starting_address;
    sym_table::get_instance().insert(get_label(), sic_assembler::location_counter);
}