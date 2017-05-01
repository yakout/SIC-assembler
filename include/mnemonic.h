//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_MNEMONIC_H
#define SIC_XE_ASSEMBLER_MNEMONIC_H


#include <iostream>
using namespace std;

class mnemonic {
private:
    string name;
    bool _is_directive;
    bool _is_extended;
public:
//    mnemonic(string name, bool directive, bool extended) {
//        this->name = name;
//        _is_directive = directive;
//        _is_extended = extended;
//    }
    mnemonic(string);
    string get_opcode();
    string get_name();
    bool is_directive();
    bool is_extended();
};

#endif //SIC_XE_ASSEMBLER_MNEMONIC_H
