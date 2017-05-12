//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_MNEMONIC_H__
#define SIC_XE_ASSEMBLER_MNEMONIC_H__


#include <iostream>
#include <unordered_map>
#include <set>
#include <operand.h>

class mnemonic {
private:
    std::string name;
    std::unordered_map<std::string, std::set<operand::operand_type> > valid_operands;
public:
    mnemonic(std::string);

    std::string get_opcode();

    std::string get_name();

    bool is_directive();

    bool operator==(std::string);

    bool operator!=(std::string);

    void initialize_map();

    bool is_valid_operand(operand *_operand);
};

#endif // SIC_XE_ASSEMBLER_MNEMONIC_H__
