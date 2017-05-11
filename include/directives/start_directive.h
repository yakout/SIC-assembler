//
// Created by Ahmed Yakout on 5/10/17.
//

#ifndef SIC_ASSEMBLER_START_DIRECTIVE_H
#define SIC_ASSEMBLER_START_DIRECTIVE_H


#include <string>
#include <directives/directive.h>

class start_directive: public directive {
private:
	static int count;
public:
    start_directive(std::string);
    virtual void handle();
};


#endif