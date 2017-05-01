//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_OPERAND_H
#define SIC_XE_ASSEMBLER_OPERAND_H

#include <string>

enum class operand_type {
    ASTRIC, // ccc      equ     *
    NUMBER, // aaa      resw    1
    LETERAL, // LDA     =C'string' / LDA =X'F23'   / LDA   =1234
    EXPRESION, //VALUE EQU SYMTAB+6   // blah equ bla1-bla2
    REGISTER, // CLEAR   A
    TWO_REGISTERS, // COMPR   A,T
    LABEL, // LDA TEMP
    ADDRESS // START 0x1000
};

class operand {
public:
    operand(std::string);

    bool is_indexing();

    bool is_indirect();

    bool is_immediate();
};


#endif //SIC_XE_ASSEMBLER_OPERAND_H
