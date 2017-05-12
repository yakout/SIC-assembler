//
// Created by Ahmed Yakout on 5/11/17.
//

#ifndef SIC_ASSEMBLER_OUT_OF_RANGE_H__
#define SIC_ASSEMBLER_OUT_OF_RANGE_H__

#include <errors/pass_one/pass_one_error.h>
#include <string>

class operand_out_of_range: public pass_one_error {
private:
	static const std::string ERR_MSG;
public:
	operand_out_of_range();
	virtual const char* what() const throw();
};

#endif // SIC_ASSEMBLER_OUT_OF_RANGE_H__