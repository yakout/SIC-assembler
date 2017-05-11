//
// Created by Ahmed Yakout on 5/11/17.
//


#include <null_instruction.h>

null_instruction::null_instruction(): instruction("") {

}

void null_instruction::handle() {
	// do nothing;
	return;
}

std::string null_instruction::get_opcode() {
	return "";
}