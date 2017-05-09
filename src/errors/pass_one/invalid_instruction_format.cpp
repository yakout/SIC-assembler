//
// Created by Ahmed Yakout on 5/8/17.
//

#include <errors/pass_one/invalid_instruction_format.h>

const std::string invalid_instruction_format::ERR_MSG = "Invalid Instruction Format";

invalid_instruction_format::invalid_instruction_format(): pass_one_error() {

}

const char* invalid_instruction_format::what() const throw() {
	return invalid_instruction_format::ERR_MSG.c_str();
}
