//
// Created by Ahmed Yakout on 5/10/17.
//

#include <directives/end_directive.h>
#include <tables/lit_table.h>
#include <errors/pass_one/duplicate_end_directive.h>

int end_directive::count = 0;

end_directive::end_directive(std::string inst_str): directive(inst_str) {
	end_directive::count++;
}

void end_directive::handle() {
	if (end_directive::count > 1) {
		throw duplicate_end_directive();
	}
    
    if (!lit_table::get_instance().get_unassigned_literals().empty()) {
        lit_table::get_instance().append_unassgined_literals();
    }

    // // check if end statement has a valid label
    // if (has_operand() && get_operand()->get_type()
    //                                         == operand::operand_type::LABEL) {
    //     if (!sym_table::get_instance().lookup(get_operand()->get_name())) {
    //         throw undefined_symbol();
    //     }
    // }
}