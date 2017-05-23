//
// Created by Ahmed Yakout on 5/10/17.
//

#ifndef SIC_ASSEMBLER_OPERATION_H__
#define SIC_ASSEMBLER_OPERATION_H__

#include <string>
#include <instruction.h>

class operation: public instruction {
public:
    operation(std::string);
    virtual void handle();
};

#endif // SIC_ASSEMBLER_OPERATION_H__
