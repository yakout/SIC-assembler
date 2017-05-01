//
// Created by Ahmed Yakout on 4/24/17.
//

#ifndef SIC_XE_ASSEMBLER_PASS_TWO_H
#define SIC_XE_ASSEMBLER_PASS_TWO_H

#include "file_reader.h"

class pass_two {
private:
    file_reader *reader;
public:
    pass_two(file_reader*);
    void pass(); // this method to start the pass one of the compiler
};

#endif //SIC_XE_ASSEMBLER_PASS_TWO_H
