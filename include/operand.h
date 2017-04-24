//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_OPERAND_H
#define SIC_XE_ASSEMBLER_OPERAND_H


enum class operand_type {

};

class operand {
public:
    bool is_indexing();
    bool is_indirect();
    bool is_immediate();
};


#endif //SIC_XE_ASSEMBLER_OPERAND_H
