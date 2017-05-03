//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_OPERAND_H
#define SIC_XE_ASSEMBLER_OPERAND_H

#include <string>
#include "iostream"

class operand {
public:
    enum class operand_type {
        LOC_COUNTER, // ccc      equ     *
        DECIMAL_ADDRESS, // aaa      resw    1
        HEXA_ADDRESS, // START 0x1000
        LABEL, // LDA TEMP
        LABEL_INDEXED,
        REGISTER, // CLEAR   A
        TWO_REGISTERS, // COMPR   A,T
        EXPRESION, //VALUE EQU SYMTAB+6   // blah equ bla1-bla2
        WORD_LITERAL, // LDA     =C'string' / LDA =C'F23'   / LDA   =1234
        HEXA_LITERAL // LDA     =C'string' / LDA =X'F23'   / LDA   =1234
    };

private:
    std::string name;
    operand_type type;
public:
    operand(std::string);

    bool is_indexing();

    bool is_indirect();

    bool is_immediate();

    bool is_hex_address();

    bool is_direct();

    std::string get_name();

    operand_type get_type();

    int get_length();
};


#endif //SIC_XE_ASSEMBLER_OPERAND_H
