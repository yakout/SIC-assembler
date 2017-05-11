//
// Created by Ahmed Yakout on 5/10/17.
//

#include <directives/equ_directive.h>
#include <tables/sym_table.h>
#include <assembler.h>
#include <errors/pass_one/duplicate_symbol.h>
#include <errors/pass_one/invalid_forward_reference.h>

equ_directive::equ_directive(std::string inst_str): directive(inst_str) {

}

void equ_directive::handle() {
    // equ doesn't change LC.
    std::string operand_field = directive::get_operand()->get_name();
    if (sym_table::get_instance().lookup(directive::get_label())) {
    	throw duplicate_symbol();
    }
    if (operand_field == "*") {
		sym_table::get_instance().insert(directive::get_label(), sic_assembler::location_counter);
    } else if (sym_table::get_instance().lookup(operand_field)) {
    	sym_table::get_instance().insert(directive::get_label(), sym_table::get_instance().get(operand_field));
    } else {
    	throw invalid_forward_reference();
    }
}