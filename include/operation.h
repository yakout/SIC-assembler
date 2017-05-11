//
// Created by Ahmed Yakout on 5/10/17.
//

#ifndef SIC_XE_ASSEMBLER_OPERATION_H
#define SIC_XE_ASSEMBLER_OPERATION_H

#include <string>
#include <instruction.h>

class operation: public instruction {
public:
    operation(std::string);
    virtual void handle();
};

#endif //SIC_XE_ASSEMBLER_INSTRUCTION_H
