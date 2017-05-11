//
// Created by Ahmed Yakout on 5/10/17.
//

#include <directives/ltorg_directive.h>
#include <tables/lit_table.h>

ltorg_directive::ltorg_directive(std::string inst_str): directive(inst_str) {

}

void ltorg_directive::handle() {
    if (!lit_table::get_instance().get_unassigned_literals().empty()) {
        lit_table::get_instance().append_unassgined_literals();
    }
}