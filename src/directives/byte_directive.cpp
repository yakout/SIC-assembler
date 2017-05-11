//
// Created by Ahmed Yakout on 5/10/17.
//

#include <directives/byte_directive.h>
#include <assembler.h>
#include <tables/sym_table.h>
#include <tables/lit_table.h>
#include <errors/pass_one/duplicate_symbol.h>

byte_directive::byte_directive(std::string inst_str): directive(inst_str) {

}

void byte_directive::handle() {
    std::string operand_field = get_operand()->get_name();

    if (get_operand()->is_literal()) {
    	lit_table::get_instance().insert(operand_field);
    }

    if (sym_table::get_instance().lookup(directive::get_label())) {
    	throw duplicate_symbol();
    } else {
    	sym_table::get_instance().insert(directive::get_label(), sic_assembler::location_counter);
    }

    sic_assembler::location_counter += get_operand()->get_length();
}