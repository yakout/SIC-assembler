//
// Created by Ahmed Yakout on 5/14/17.
//

#include <errors/invalid_expression.h>

const std::string invalid_expression::ERR_MSG = "Invalid Expression";

invalid_expression::invalid_expression(): pass_two_error() {

}

const char* invalid_expression::what() const throw() {
	return invalid_expression::ERR_MSG.c_str();
}
