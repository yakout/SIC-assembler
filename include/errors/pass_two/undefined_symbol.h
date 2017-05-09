//
// Created by Ahmed Yakout on 5/9/17.
//

#ifndef SIC_ASSEMBLER_UNDEFINED_SYMBOL__
#define SIC_ASSEMBLER_UNDEFINED_SYMBOL__

#include <errors/pass_two/pass_two_error.h>
#include <iostream>

class undefined_symbol: public pass_two_error {
private:
	static const std::string ERR_MSG;
public:
	undefined_symbol();
	virtual const char* what() const throw();
};

#endif