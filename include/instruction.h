//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_ASSEMBLER_INSTRUCTION_H__
#define SIC_ASSEMBLER_INSTRUCTION_H__

#include <string>
#include <operand.h>
#include <mnemonic.h>

/**
 * SIC machine instruction representation.
 */
class instruction {
private:
    operand *_operand;
    mnemonic *_mnemonic;
    std::string label;
    std::string _comment;
    std::string _location;
    std::string full_instruction;
public:
    instruction(std::string);
    virtual ~instruction();

    // setters
    void set_label(std::string);
    void set_mnemonic(mnemonic *);
    void set_operand(operand *);
    void set_comment(std::string);
    void set_location(std::string);

    // getters
    std::string get_label();
    mnemonic *get_mnemonic();
    operand *get_operand();
    std::string get_comment();
    std::string get_location();
    std::string get_full_instruction();

    virtual void handle() = 0;
    virtual std::string get_object_code();
    bool has_label();
    bool has_operand();
};

#endif // SIC_ASSEMBLER_INSTRUCTION_H__
