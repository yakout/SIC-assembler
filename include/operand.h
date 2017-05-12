//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_OPERAND_H__
#define SIC_XE_ASSEMBLER_OPERAND_H__

#include <string>

class operand {
public:
    enum class operand_type {
        NONE,           //          rsub
        LOC_COUNTER,    // ccc      equ     *
        DECIMAL,        // aaa      resw    1
        HEXA,           //          START   0x1000
        LABEL,          //          LDA     TEMP
        LABEL_INDEXED,  //          LDA     buffer,x
        STRING,         // EOF      BYTE    C'EOF'
        HEXA_STRING,    // DEV      BYTE    X'F1'
        EXPRESSION,     // VALUE    EQU     SYMTAB+6   // blah equ bla1-bla2
        WORD_LITERAL,   //          LDA     =3
        CHAR_LITERAL,   //          LDA     =C'string'
        HEXA_LITERAL,   //          LDA     =X'F23'
        DECIMAL_ARRAY   // ARR      WORD    1,2,3
    };

private:
    std::string name;
    operand_type type;
    std::string address;
public:
    static const int OPERAND_WIDTH = 4;
    static const int OPCODE_WIDTH = 2;
    static const int MAX_DECIMAL_ADDRESS = (1 << 16) - 1;

    operand(std::string);
    ~operand();

    /**
     * @return operand::operand_tpye the type of operand.
     */
    operand::operand_type get_type();
    /**
     * @return std::string name the operand value as string.
     */
    std::string get_name();
    /**
     * Converts symbolic operands to their equivalent machine addresses.
     * Converts data constants specified in the source program into their internal machine representation.
     * 
     * @return 4 digits hexadecimal address of the operand.
     *         If the operand is constant (e.g C'EOF') it will return it's value in hexadecimal (e.g 454F46)
     *         If the operand type is NONE it will return 0000.
     */
    std::string get_address();
    /**
     * @return true of the operand type matches any literal form:  
     * (=x'[a-z0-9]') -> hex values
     * (=c'[a-z]') -> characters
     * (=[0-9]) -> numbers
     */
    bool is_literal();
    /**
     * @return the number of bytes in x'' or c''.
     * otherwise it will return the length of operand::name.
     */
    int get_length();
};

#endif // SIC_XE_ASSEMBLER_OPERAND_H__
