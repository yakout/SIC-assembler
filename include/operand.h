//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_OPERAND_H
#define SIC_XE_ASSEMBLER_OPERAND_H

#include <string>

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
        EXPRESSION, //VALUE EQU SYMTAB+6   // blah equ bla1-bla2
        WORD_LITERAL, // LDA     =3
        CHAR_LITERAL, // LDA     =C'string'
        HEXA_LITERAL, // LDA     =X'F23'
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

    operand::operand_type get_type();
    std::string get_name();
    std::string get_opcode();
    bool is_literal();
    int get_length();

};


#endif //SIC_XE_ASSEMBLER_OPERAND_H
