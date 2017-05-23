//
// Created by Ahmed Yakout on 5/10/17.
//

#include <directives/org_directive.h>
#include <assembler.h>
#include <expression_evaluator.h>
#include <tables/sym_table.h>

org_directive::org_directive(std::string inst_str): directive(inst_str) {

}


void org_directive::handle() {
    if (!has_operand()) {
        if (sic_assembler::location_counter_old == 0) {
            // do nothing since there is no old value set before
            // and org has first appeared with no operand address.
        } else {
            // reset location counter
            sic_assembler::location_counter = sic_assembler::location_counter_old;
        }
    } else {
        // save location counter to reset it if another org directive has appeared with no address in operand.
        sic_assembler::location_counter_old = sic_assembler::location_counter;
        // update location counter.
        
        operand::operand_type type = get_operand()->get_type();
        std::string operand_name = get_operand()->get_name();

        if (type == operand::operand_type::EXPRESSION) {
            expression_evaluator evaluator(operand_name);
            sic_assembler::location_counter = sic_assembler::hex_to_int(evaluator.evaluate());
        } else if (type == operand::operand_type::LABEL) { 
            sic_assembler::location_counter = sym_table::get_instance().get(operand_name);
        } else if (type == operand::operand_type::HEXA) { 
            sic_assembler::location_counter = sic_assembler::hex_to_int(operand_name);
        } else if (type == operand::operand_type::HEXA_LITERAL) { 
            sic_assembler::location_counter = sic_assembler::hex_to_int(operand_name.substr(3, operand_name.length() - 4));
        }
    } 
}