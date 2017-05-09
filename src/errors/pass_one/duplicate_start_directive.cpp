//
// Created by Ahmed Yakout on 5/9/17.
//

#include <errors/pass_one/duplicate_start_directive.h>

const std::string duplicate_start_directive::ERR_MSG = "Duplicate start directive";

duplicate_start_directive::duplicate_start_directive(): pass_one_error() {
	
}

const char* duplicate_start_directive::what() const throw() {
	return duplicate_start_directive::ERR_MSG.c_str();
}