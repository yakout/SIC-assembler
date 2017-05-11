//
// Created by Ahmed Yakout on 5/9/17.
//

#ifndef SIC_ASSEMBLER_PASS_ONE_ERROR__
#define SIC_ASSEMBLER_PASS_ONE_ERROR__

#include <errors/assembler_error.h>
#include <string>

class pass_one_error: public assembler_error {
public:
	pass_one_error();
	virtual const char* what() const throw() = 0;
};

#endif