//
// Created by Ahmed Yakout on 4/24/17.
//

#ifndef SIC_XE_ASSEMBLER_PASS_ONE_H__
#define SIC_XE_ASSEMBLER_PASS_ONE_H__

#include <file_handlers/file_reader.h>

class pass_one {
private:
    std::unique_ptr<file_reader> reader;
    std::string path;
    std::string file_name;
public:
    pass_one(std::unique_ptr<file_reader>, std::string, std::string);
    void pass(); // this method to start the pass one of the compiler
};

#endif // SIC_XE_ASSEMBLER_PASS_ONE_H__
