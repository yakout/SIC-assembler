//
// Created by Ahmed Yakout on 5/11/17.
//

#include <errors/pass_one/invalid_mnemonic.h>

const std::string invalid_mnemonic::ERR_MSG = "Invalid Mnemonic";

invalid_mnemonic::invalid_mnemonic(): pass_one_error() {
	
}

const char* invalid_mnemonic::what() const throw() {
	return invalid_mnemonic::ERR_MSG.c_str();
}