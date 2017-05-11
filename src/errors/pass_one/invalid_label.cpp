//
// Created by Ahmed Yakout on 5/11/17.
//

#include <errors/pass_one/invalid_label.h>

const std::string invalid_label::ERR_MSG = "Invalid Label format: [A-Za-z]+[0-9]";

invalid_label::invalid_label(): pass_one_error() {
	
}

const char* invalid_label::what() const throw() {
	return invalid_label::ERR_MSG.c_str();
}