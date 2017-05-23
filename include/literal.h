//
// Created by Ahmed Yakout on 5/22/17.
//

#ifndef SIC_ASSEMBLER_LITERAL_H__
#define SIC_ASSEMBLER_LITERAL_H__

#include <string>
#include <instruction.h>

class literal: public instruction {
public:
    literal(std::string);
    virtual std::string get_object_code();
    virtual void handle();
};

#endif // SIC_ASSEMBLER_LITERAL_H__
