//
// Created by Ahmed Yakout on 5/10/17.
//

#ifndef SIC_ASSEMBLER_DIRECTIVE_H__
#define SIC_ASSEMBLER_DIRECTIVE_H__


#include <string>
#include <instruction.h>

class directive: public instruction {
public:
    directive(std::string s): instruction(s) {

    }
    virtual void handle() = 0;
};


#endif // SIC_ASSEMBLER_DIRECTIVE_H__