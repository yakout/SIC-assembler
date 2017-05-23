//
// Created by Ahmed Yakout on 5/14/17.
//

#ifndef SIC_ASSEMBLER_INVALID_EXPRESSION_H__
#define SIC_ASSEMBLER_INVALID_EXPRESSION_H__

#include <errors/pass_two/pass_two_error.h>
#include <errors/pass_one/pass_one_error.h>
#include <string>

class invalid_expression: public pass_two_error, public pass_one_error {
private:
	static const std::string ERR_MSG;
public:
	invalid_expression();
	virtual const char* what() const throw();
};

#endif // SIC_ASSEMBLER_INVALID_EXPRESSION_H__