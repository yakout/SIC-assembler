//
// Created by Ahmed Yakout on 5/10/17.
//

#ifndef SIC_ASSEMBLER_LTORG_DIRECTIVE_H
#define SIC_ASSEMBLER_LTORG_DIRECTIVE_H

#include <string>
#include <directives/directive.h>

class ltorg_directive: public directive {
public:
    ltorg_directive(std::string);
    virtual void handle();
};

#endif