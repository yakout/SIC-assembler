//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_INSTRUCTION_H
#define SIC_XE_ASSEMBLER_INSTRUCTION_H

#include <iostream>
#include "operand.h"
#include "mnemonic.h"

class instruction {
private:
    operand *_operand;
    mnemonic *_mnemonic;
    std::string label;
    std::string comment;
    std::string location;
//    std::string full_instr;

public:
    instruction();
    ~instruction();

    std::string get_opcode();

    bool has_label();

    bool has_operand();

    // setters
    void set_label(std::string);

    void set_mnemonic(mnemonic *);

    void set_operand(operand *);

    void set_comment(std::string);

    void set_location(std::string);

    // getters
    std::string get_label();

    mnemonic *get_mnemonic();

    operand *get_operand();

    std::string get_comment();

    std::string get_location();
};

#endif //SIC_XE_ASSEMBLER_INSTRUCTION_H
