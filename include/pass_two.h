//
// Created by Ahmed Yakout on 4/24/17.
//

#ifndef SIC_XE_ASSEMBLER_PASS_TWO_H
#define SIC_XE_ASSEMBLER_PASS_TWO_H

class pass_two {
private:
    input_reader reader;
public:
    pass_two(input_reader);
    void pass(); // this method to start the pass one of the compiler
};

#endif //SIC_XE_ASSEMBLER_PASS_TWO_H
