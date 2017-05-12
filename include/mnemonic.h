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
    bool operator==(std::string);
    bool operator!=(std::string);

    /**
     * @return The mnemonic's operation code in it's machine language equivalent.
     */
    std::string get_opcode();
    /**
     * @return the name of mnemonic as string.
     */
    std::string get_name();
    /**
     * @return true if the mnemonic is one of the assembler directives.
     */
    bool is_directive();
    /**
     * Intializes map that will be used to verify each mnemonic with it's valid operand types.
     */
    void initialize_map();
    /**
     * @param instruction's operand
     * @return true if the operand type is comaptible with the mnemonic.
     */
    bool is_valid_operand(operand *_operand);
};

#endif // SIC_XE_ASSEMBLER_MNEMONIC_H__
