//
// Created by Ahmed Yakout on 5/9/17.
//

#ifndef SIC_ASSEMBLER_MISSING_END_DIRECTIVE__
#define SIC_ASSEMBLER_MISSING_END_DIRECTIVE__

#include <errors/pass_one/pass_one_error.h>
#include <string>

class missing_end_directive: public pass_one_error {
private:
	static const std::string ERR_MSG;
public:
	missing_end_directive();
	virtual const char* what() const throw();
};

#endif