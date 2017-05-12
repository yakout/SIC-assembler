//
// Created by Ahmed Yakout on 5/10/17.
//

#ifndef SIC_ASSEMBLER_RESB_DIRECTIVE_H__
#define SIC_ASSEMBLER_RESB_DIRECTIVE_H__


#include <string>
#include <directives/directive.h>

class resb_directive: public directive {
public:
    resb_directive(std::string);
    virtual void handle();
};


#endif // SIC_ASSEMBLER_RESB_DIRECTIVE_H__