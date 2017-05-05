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
    std::string _comment;
    std::string _location;
    int _line_number;
    std::string full_instruction;
public:
    instruction(std::string);
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

    void set_line_number(int);

    // getters
    std::string get_label();

    mnemonic *get_mnemonic();

    operand *get_operand();

    std::string get_comment();

    std::string get_location();

    int get_line_number();

    std::string get_full_instruction();
};

#endif //SIC_XE_ASSEMBLER_INSTRUCTION_H
