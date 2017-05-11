//
// Created by Ahmed Yakout on 5/10/17.
//

#ifndef SIC_ASSEMBLER_DIRECTIVE_H
#define SIC_ASSEMBLER_DIRECTIVE_H


#include <string>
#include <instruction.h>

class directive: public instruction {
public:
    directive(std::string s): instruction(s) {

    }
    virtual void handle() = 0;
};


#endif