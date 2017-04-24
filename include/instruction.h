//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_INSTRUCTION_H
#define SIC_XE_ASSEMBLER_INSTRUCTION_H

#include <iostream>
#include <operand.h>
#include <mnemonic.h>

using namespace std;

class instruction {
private:
    mnemonic _menmonic;

public:
    bool has_label();

    // setters
    void set_label(string);
    void set_mnemonic(mnemonic);
    void set_operand(operand);
    void set_comment(string);

    // getters
    string get_label();
    mnemonic get_mnemonic();
    operand get_operand();
    string get_comment();

};

#endif //SIC_XE_ASSEMBLER_INSTRUCTION_H
