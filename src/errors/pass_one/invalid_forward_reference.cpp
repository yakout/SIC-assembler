//
// Created by Ahmed Yakout on 5/11/17.
//

#include <errors/pass_one/invalid_forward_reference.h>

const std::string invalid_forward_reference::ERR_MSG = "Forward Reference is NOT allowed here";

invalid_forward_reference::invalid_forward_reference(): pass_one_error() {
	
}

const char* invalid_forward_reference::what() const throw() {
	return invalid_forward_reference::ERR_MSG.c_str();
}