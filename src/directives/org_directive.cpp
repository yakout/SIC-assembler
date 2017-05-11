//
// Created by Ahmed Yakout on 5/10/17.
//

#include <directives/org_directive.h>
#include <assembler.h>

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
        sic_assembler::location_counter = sic_assembler::hex_to_int(get_operand()->get_name());
    } 
}