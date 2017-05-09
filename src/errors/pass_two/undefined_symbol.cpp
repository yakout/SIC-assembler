//
// Created by Ahmed Yakout on 5/9/17.
//

#include <errors/pass_two/undefined_symbol.h>

const std::string undefined_symbol::ERR_MSG = "Undefined Symbol";

undefined_symbol::undefined_symbol(): pass_two_error() {

}

const char* undefined_symbol::what() const throw() {
	return undefined_symbol::ERR_MSG.c_str();
}
