//
// Created by Ahmed Yakout on 5/11/17.
//

#ifndef SIC_ASSEMBLER_INVALID_MNEMONIC_H__
#define SIC_ASSEMBLER_INVALID_MNEMONIC_H__

#include <errors/pass_one/pass_one_error.h>
#include <string>

class invalid_mnemonic: public pass_one_error {
private:
	static const std::string ERR_MSG;
public:
	invalid_mnemonic();
	virtual const char* what() const throw();
};

#endif // SIC_ASSEMBLER_INVALID_MNEMONIC_H__