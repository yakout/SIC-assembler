//
// Created by Ahmed Yakout on 5/10/17.
//

#include <directives/resw_directive.h>
#include <assembler.h>
#include <tables/sym_table.h>
#include <errors/pass_one/duplicate_symbol.h>

resw_directive::resw_directive(std::string inst_str): directive(inst_str) {

}

void resw_directive::handle() {                                           
    std::string operand_field = directive::get_operand()->get_name();
    if (sym_table::get_instance().lookup(directive::get_label())) {
    	throw duplicate_symbol();
    } else {
    	sym_table::get_instance().insert(directive::get_label(), sic_assembler::location_counter);
    }

    sic_assembler::location_counter += sic_assembler::INSTRUCTION_LENGTH
                                               * std::stoi(get_operand()->get_name());
}