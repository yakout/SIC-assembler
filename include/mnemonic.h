//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_MNEMONIC_H
#define SIC_XE_ASSEMBLER_MNEMONIC_H


#include <iostream>

class mnemonic {
private:
    std::string name;
public:
    mnemonic(std::string);

    std::string get_opcode();

    std::string get_name();

    bool is_directive();

    bool operator==(std::string);
};

#endif //SIC_XE_ASSEMBLER_MNEMONIC_H
