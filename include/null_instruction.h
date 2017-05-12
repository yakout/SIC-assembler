//
// Created by Ahmed Yakout on 5/11/17.
//

#ifndef SIC_ASSEMBLER_NULL_INSTRUCTION_H__
#define SIC_ASSEMBLER_NULL_INSTRUCTION_H__

#include <string>
#include <instruction.h>

/**
 * Null object desgin pattern.
 * Represents null instruction which indicates there is no more instructions are found in file.
 */
class null_instruction: public instruction {
public:
    null_instruction();
    virtual void handle();
};


#endif // SIC_ASSEMBLER_NULL_INSTRUCTION_H__
