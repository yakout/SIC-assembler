//
// Created by Ahmed Yakout on 5/10/17.
//

#include <directives/word_directive.h>
#include <assembler.h>
#include <tables/sym_table.h>
#include <errors/pass_one/duplicate_symbol.h>

word_directive::word_directive(std::string inst_str): directive(inst_str) {

}

void word_directive::handle() {
    std::string operand_field = directive::get_operand()->get_name();
    if (sym_table::get_instance().lookup(directive::get_label())) {
        throw duplicate_symbol();
    } else {
        sym_table::get_instance().insert(directive::get_label(), sic_assembler::location_counter);
    }

    // handle location counter
    if (get_operand()->get_type() == operand::operand_type::DECIMAL_ARRAY) {
            std::string str = get_operand()->get_name();
            sic_assembler::location_counter += sic_assembler::INSTRUCTION_LENGTH 
                                             * (std::count(str.begin(), str.end(), ',') + 1);
    } else {
		sic_assembler::location_counter += sic_assembler::INSTRUCTION_LENGTH;
    }
}