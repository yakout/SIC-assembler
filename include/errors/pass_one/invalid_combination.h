//
// Created by Ahmed Yakout on 5/11/17.
//


#ifndef SIC_ASSEMBLER_INVALID_COMBINATION_H__
#define SIC_ASSEMBLER_INVALID_COMBINATION_H__

#include <errors/pass_one/pass_one_error.h>
#include <string>

class invalid_combination: public pass_one_error {
private:
	static const std::string ERR_MSG;
public:
	invalid_combination();
	virtual const char* what() const throw();
};

#endif // SIC_ASSEMBLER_INVALID_COMBINATION_H__