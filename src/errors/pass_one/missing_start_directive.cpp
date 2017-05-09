//
// Created by Ahmed Yakout on 5/8/17.
//

#include <errors/pass_one/missing_start_directive.h>

const std::string missing_start_directive::ERR_MSG = "No START directive found";

missing_start_directive::missing_start_directive(): pass_one_error() {
	
}

const char* missing_start_directive::what() const throw() {
	return missing_start_directive::ERR_MSG.c_str();
}