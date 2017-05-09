//
// Created by Ahmed Yakout on 5/8/17.
//

#ifndef SIC_ASSEMBLER_INVALID_INSTRUCTION_FORMAT__
#define SIC_ASSEMBLER_INVALID_INSTRUCTION_FORMAT__

#include <errors/pass_one/pass_one_error.h>
#include <iostream>

class invalid_instruction_format: public pass_one_error {
private:
	static const std::string ERR_MSG;
public:
	invalid_instruction_format();
	virtual const char* what() const throw();
};

#endif