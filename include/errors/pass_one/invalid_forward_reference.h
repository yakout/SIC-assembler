//
// Created by Ahmed Yakout on 5/11/17.
//

#ifndef SIC_ASSEMBLER_FORWARD_REFERENCE__
#define SIC_ASSEMBLER_FORWARD_REFERENCE__

#include <errors/pass_one/pass_one_error.h>
#include <string>

class invalid_forward_reference: public pass_one_error {
private:
	static const std::string ERR_MSG;
public:
	invalid_forward_reference();
	virtual const char* what() const throw();
};

#endif