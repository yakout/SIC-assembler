//
// Created by Ahmed Yakout on 4/24/17.
//

#ifndef SIC_XE_ASSEMBLER_PASS_ONE_H
#define SIC_XE_ASSEMBLER_PASS_ONE_H

#include "file_reader.h"

class pass_one {
private:
    file_reader *reader;
public:
    pass_one(file_reader*); // todo this constructor should take the input_reader (by marwan)
    void pass(); // this method to start the pass one of the compiler
};

#endif //SIC_XE_ASSEMBLER_PASS_ONE_H
