//
// Created by Ahmed Yakout on 5/10/17.
//

#include <literal.h>
#include <assembler.h>
#include <tables/lit_table.h>

literal::literal(std::string instr_str): instruction(instr_str) {
}

std::string literal::get_object_code() {
	std::string _literal = instruction::get_mnemonic()->get_name(); 
	std::string object_code;

	if (_literal[1] == 'x') {
		std::string value = _literal.substr(3, _literal.length() - 4);
        object_code = value;
    } else if (_literal[1] == 'c') {
    	std::string value = _literal.substr(3, _literal.length() - 4);
        object_code = "";
        for (int i = 0; i < value.length(); i++){
            object_code += sic_assembler::decimal_to_hex((int) value[i], 2);
        }
    } else {
        std::string value = _literal.substr(1);
        object_code = sic_assembler::decimal_to_hex(stoi(value), 6);
        // std::cout << object_code << std::endl;
    }

  return object_code;
}

void literal::handle() {
  // do nothing
}