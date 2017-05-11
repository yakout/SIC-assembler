//
// Created by Ahmed Yakout on 5/11/17.
//

#include <errors/pass_one/invalid_combination.h>

const std::string invalid_combination::ERR_MSG = "Invalid operand type for mnemonic";

invalid_combination::invalid_combination(): pass_one_error() {
	
}

const char* invalid_combination::what() const throw() {
	return invalid_combination::ERR_MSG.c_str();
}