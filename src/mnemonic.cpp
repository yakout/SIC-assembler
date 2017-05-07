//
// Created by Ahmed Yakout on 4/23/17.
//

#include "assembler.h"
#include "mnemonic.h"
#include "op_table.h"

mnemonic::mnemonic(std::string name) {
    mnemonic::initialize_map();
    if (!op_table::get_instance().lookup(name) && sic_assembler::is_directive(name)) {
        throw "Invalid Mnemonic";
    }
    mnemonic::name = sic_assembler::trim(name);
}

std::string mnemonic::get_name() {
    return mnemonic::name;
}

std::string mnemonic::get_opcode() {
    return op_table::get_instance().get(mnemonic::name);
}

bool mnemonic::is_directive() {
    return sic_assembler::is_directive(name);
}

bool mnemonic::operator==(std::string second_mnemonic_name) {
    return sic_assembler::trim(name) == second_mnemonic_name;
}

bool mnemonic::operator!=(std::string second_mnemonic_name) {
    return !(*this == second_mnemonic_name);
}

bool mnemonic::is_valid_operand(operand *_operand) {
    return mnemonic::valid_operands[mnemonic::get_name()].count(_operand->get_type()) != 0;
}

void mnemonic::initialize_map(){
    valid_operands["add"] = {operand::operand_type::HEXA, operand::operand_type::LOC_COUNTER,
                             operand::operand_type::LABEL, operand::operand_type::LABEL_INDEXED,
                             operand::operand_type::EXPRESSION};
    valid_operands["sub"] = valid_operands["add"];
    valid_operands["mul"] = valid_operands["add"];
    valid_operands["div"] = valid_operands["add"];
    valid_operands["and"] = valid_operands["add"];
    valid_operands["or"] = valid_operands["add"];
    valid_operands["comp"] = valid_operands["add"];
    valid_operands["tix"] = valid_operands["add"];
    valid_operands["lda"] = valid_operands["add"];
    valid_operands["ldl"] = valid_operands["add"];
    valid_operands["ldx"] = valid_operands["add"];
    valid_operands["sta"] = valid_operands["add"];
    valid_operands["stl"] = valid_operands["add"];
    valid_operands["stx"] = valid_operands["add"];
    valid_operands["ldch"] = valid_operands["add"];
    valid_operands["stch"] = valid_operands["add"];

    valid_operands["j"] = {operand::operand_type::HEXA, operand::operand_type::LOC_COUNTER,
                           operand::operand_type::LABEL, operand::operand_type::EXPRESSION};
    valid_operands["jgt"] = valid_operands["j"];
    valid_operands["jeq"] = valid_operands["j"];
    valid_operands["jlt"] = valid_operands["j"];
    valid_operands["jsub"] = valid_operands["j"];
    valid_operands["td"] = valid_operands["j"];
    valid_operands["rd"] = valid_operands["j"];
    valid_operands["wd"] = valid_operands["j"];

    valid_operands["rsub"] = {operand::operand_type::NONE};

    valid_operands["byte"] = {operand::operand_type::HEXA_STRING, operand::operand_type::STRING};

    valid_operands["resb"] = valid_operands["resw"] = {operand::operand_type::DECIMAL};

    valid_operands["word"] = {operand::operand_type::HEXA_STRING, operand::operand_type::DECIMAL, operand::operand_type::DECIMAL_ARRAY};

    valid_operands["start"] = {operand::operand_type::HEXA, operand::operand_type::NONE};
    valid_operands["end"] = {operand::operand_type::HEXA, operand::operand_type::NONE,
                             operand::operand_type::LABEL, operand::operand_type::EXPRESSION};

}

