//
// Created by Marwan Tammam on 4/30/17.
//

#ifndef SIC_XE_ASSEMBLER_FILE_READER_H
#define SIC_XE_ASSEMBLER_FILE_READER_H

#include <fstream>
#include <string>
#include <regex>
#include "instruction.h"

class file_reader {
private:
    std::ifstream source_file;
    std::string buffer;
    int current_line_number = 1;
public:
    file_reader(std::string);
    ~file_reader();

    bool has_next_instruction();

    bool is_comment_line();

    instruction *get_next_instruction();
};

#endif //SIC_XE_ASSEMBLER_FILE_READER_H
