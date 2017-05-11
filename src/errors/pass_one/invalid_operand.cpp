//
// Created by Ahmed Yakout on 5/11/17.
//

#include <errors/pass_one/invalid_operand.h>

const std::string invalid_operand::ERR_MSG = "Invalid Operand";

invalid_operand::invalid_operand(): pass_one_error() {
	
}

const char* invalid_operand::what() const throw() {
	return invalid_operand::ERR_MSG.c_str();
}