//
// Created by Ahmed Yakout on 5/9/17.
//

#ifndef SIC_ASSEMBLER_DUPLICATE_SYMBOL__
#define SIC_ASSEMBLER_DUPLICATE_SYMBOL__

#include <errors/pass_one/pass_one_error.h>
#include <string>

class duplicate_symbol: public pass_one_error {
private:
	static const std::string ERR_MSG;
public:
	duplicate_symbol();
	virtual const char* what() const throw();
};

#endif