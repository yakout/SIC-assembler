//
// Created by Ahmed Yakout on 5/10/17.
//

#ifndef SIC_ASSEMBLER_END_DIRECTIVE_H__
#define SIC_ASSEMBLER_END_DIRECTIVE_H__

#include <string>
#include <directives/directive.h>

class end_directive: public directive {
private:
	static int count;
public:
    end_directive(std::string);
    virtual void handle();
};

#endif // SIC_ASSEMBLER_END_DIRECTIVE_H__