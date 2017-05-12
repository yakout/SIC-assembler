//
// Created by Ahmed Yakout on 5/9/17.
//

#ifndef SIC_ASSEMBLER_DUPLICATE_START_DIRECTIVE_H__
#define SIC_ASSEMBLER_DUPLICATE_START_DIRECTIVE_H__

#include <errors/pass_one/pass_one_error.h>
#include <string>

class duplicate_start_directive: public pass_one_error {
private:
	static const std::string ERR_MSG;
public:
	duplicate_start_directive();
	virtual const char* what() const throw();
};

#endif // SIC_ASSEMBLER_DUPLICATE_START_DIRECTIVE_H__