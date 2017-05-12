//
// Created by Ahmed Yakout on 5/8/17.
//

#ifndef SIC_ASSEMBLER_INVALID_INSTRUCTION_FORMAT_H__
#define SIC_ASSEMBLER_INVALID_INSTRUCTION_FORMAT_H__

#include <errors/pass_one/pass_one_error.h>
#include <string>

class invalid_instruction_format: public pass_one_error {
private:
	static const std::string ERR_MSG;
public:
	invalid_instruction_format();
	virtual const char* what() const throw();
};

#endif // SIC_ASSEMBLER_INVALID_INSTRUCTION_FORMAT_H__