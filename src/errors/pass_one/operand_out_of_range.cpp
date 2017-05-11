//
// Created by Ahmed Yakout on 5/11/17.
//

#include <errors/pass_one/operand_out_of_range.h>

const std::string operand_out_of_range::ERR_MSG = "Operand Out Of Range [0, 65535]";

operand_out_of_range::operand_out_of_range(): pass_one_error() {
	
}

const char* operand_out_of_range::what() const throw() {
	return operand_out_of_range::ERR_MSG.c_str();
}