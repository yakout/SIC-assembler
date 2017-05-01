//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_INSTRUCTION_H
#define SIC_XE_ASSEMBLER_INSTRUCTION_H

#include <iostream>
#include "operand.h"
#include "mnemonic.h"

using namespace std;

class instruction {
private:
    operand* _operand;
    mnemonic* _mnemonic;
    string label;
    string comment;

public:
    instruction();
    bool has_label();
    bool has_operand();
    // setters
    void set_label(string);
    void set_mnemonic(mnemonic*);
    void set_operand(operand*);
    void set_comment(string);

    // getters
    string get_label();
    mnemonic* get_mnemonic();
    operand* get_operand();
    string get_comment();

};

#endif //SIC_XE_ASSEMBLER_INSTRUCTION_H
