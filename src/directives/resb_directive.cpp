//
// Created by Ahmed Yakout on 5/10/17.
//

#include <directives/resb_directive.h>
#include <assembler.h>
#include <tables/sym_table.h>
#include <errors/pass_one/duplicate_symbol.h>

resb_directive::resb_directive(std::string inst_str): directive(inst_str) {

}

void resb_directive::handle() {
    if (sym_table::get_instance().lookup(directive::get_label())) {
    	throw duplicate_symbol();
    } else {
    	sym_table::get_instance().insert(directive::get_label(), sic_assembler::location_counter);
    }
    
    sic_assembler::location_counter += stoi(get_operand()->get_name());
}