//
// Created by Ahmed Yakout on 5/11/17.
//

#ifndef SIC_ASSEMBLER_NULL_INSTRUCTION_H
#define SIC_ASSEMBLER_NULL_INSTRUCTION_H

#include <string>
#include <instruction.h>

class null_instruction: public instruction {
public:
    null_instruction();

    virtual void handle();
    virtual std::string get_opcode();
};


#endif //SIC_XE_ASSEMBLER_INSTRUCTION_H