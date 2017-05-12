//
// Created by Ahmed Yakout on 5/10/17.
//

#ifndef SIC_ASSEMBLER_EQU_DIRECTIVE_H__
#define SIC_ASSEMBLER_EQU_DIRECTIVE_H__

#include <string>
#include <directives/directive.h>

class equ_directive: public directive {
public:
    equ_directive(std::string);
    virtual void handle();
};

#endif // SIC_ASSEMBLER_EQU_DIRECTIVE_H__