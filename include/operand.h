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
        NONE,
        LOC_COUNTER, // ccc      equ     *
        DECIMAL, // aaa      resw    1
        HEXA, // START 0x1000
        LABEL, // LDA TEMP
        LABEL_INDEXED,
        STRING,
        HEXA_STRING,
        REGISTER, // CLEAR   A
//        TWO_REGISTERS, // COMPR   A,T
        EXPRESSION, //VALUE EQU SYMTAB+6   // blah equ bla1-bla2
//        WORD_LITERAL, // LDA     =C'string' / LDA =C'F23'   / LDA   =1234
//        HEXA_LITERAL, // LDA     =C'string' / LDA =X'F23'   / LDA   =1234
        DECIMAL_ARRAY
    };

private:
    std::string name;
    operand_type type;
    std::string opcode;
public:
    static const int OPERAND_WIDTH = 4;
    static const int OPCODE_WIDTH = 2;
    static const int MAX_DECIMAL_ADDRESS = (1 << 16) - 1;

    operand(std::string);
    ~operand();

    std::string get_name();

    operand::operand_type get_type();

    int get_length();

    std::string get_opcode();
};


#endif //SIC_XE_ASSEMBLER_OPERAND_H
