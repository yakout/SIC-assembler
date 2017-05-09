//
// Created by Ahmed Yakout on 5/9/17.
//

#include <errors/pass_one/missing_end_directive.h>

const std::string missing_end_directive::ERR_MSG = "No END directive found";

missing_end_directive::missing_end_directive(): pass_one_error() {
}

const char* missing_end_directive::what() const throw() {
	return missing_end_directive::ERR_MSG.c_str();
}