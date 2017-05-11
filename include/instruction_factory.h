//
// Created by Ahmed Yakout on 5/11/17.
//

#ifndef SIC_ASSEMBLER_INSTRUCTION_FACTORY_H
#define SIC_ASSEMBLER_INSTRUCTION_FACTORY_H

#include <operand.h>
#include <mnemonic.h>
#include <instruction.h>

class instruction_factory {
private:
	std::string _buffer;
public:
	instruction_factory(std::string);
	instruction* make_instruction(std::string _location, std::string _label, mnemonic*, operand*, std::string _comment);
};

#endif