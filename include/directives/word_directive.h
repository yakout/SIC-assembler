//
// Created by Ahmed Yakout on 5/10/17.
//

#ifndef SIC_ASSEMBLER_WORD_DRIVER_H
#define SIC_ASSEMBLER_WORD_DRIVER_H

#include <string>
#include <directives/directive.h>

class word_directive: public directive {
public:
    word_directive(std::string);
    virtual void handle();
};

#endif