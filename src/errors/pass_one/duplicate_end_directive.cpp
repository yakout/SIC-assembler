//
// Created by Ahmed Yakout on 5/11/17.
//

#include <errors/pass_one/duplicate_end_directive.h>

const std::string duplicate_end_directive::ERR_MSG = "Duplicate END directive";

duplicate_end_directive::duplicate_end_directive(): pass_one_error() {
	
}

const char* duplicate_end_directive::what() const throw() {
	return duplicate_end_directive::ERR_MSG.c_str();
}