//
// Created by Ahmed Yakout on 5/9/17.
//

#include <errors/pass_one/duplicate_symbol.h>

const std::string duplicate_symbol::ERR_MSG = "Duplicate Symbol";

duplicate_symbol::duplicate_symbol(): pass_one_error() {
	
}

const char* duplicate_symbol::what() const throw() {
	return duplicate_symbol::ERR_MSG.c_str();
}