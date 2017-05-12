//
// Created by Ahmed Yakout on 5/11/17.
//

#ifndef SIC_ASSEMBLER_DUPLICATE_END_DIRECTIVE_H__
#define SIC_ASSEMBLER_DUPLICATE_END_DIRECTIVE_H__

#include <errors/pass_one/pass_one_error.h>
#include <string>

class duplicate_end_directive: public pass_one_error {
private:
	static const std::string ERR_MSG;
public:
	duplicate_end_directive();
	virtual const char* what() const throw();
};

#endif // SIC_ASSEMBLER_DUPLICATE_END_DIRECTIVE_H__