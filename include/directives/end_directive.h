//
// Created by Ahmed Yakout on 5/10/17.
//

#ifndef SIC_ASSEMBLER_END_DIRECTIVE_H
#define SIC_ASSEMBLER_END_DIRECTIVE_H

#include <string>
#include <directives/directive.h>

class end_directive: public directive {
private:
	static int count;
public:
    end_directive(std::string);
    virtual void handle();
};

#endif