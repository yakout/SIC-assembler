//
// Created by Ahmed Yakout on 5/9/17.
//

#ifndef SIC_ASSEMBLER_PASS_TWO_ERROR__
#define SIC_ASSEMBLER_PASS_TWO_ERROR__

#include <errors/assembler_error.h>
#include <iostream>

class pass_two_error: public assembler_error {
public:
	pass_two_error();
	virtual const char* what() const throw() = 0;
};

#endif