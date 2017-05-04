//
// Created by Ahmed Yakout on 5/4/17.
//

#ifndef SIC_ASSEMBLER_INTERMEDIATE_FILE_WRITER_H
#define SIC_ASSEMBLER_INTERMEDIATE_FILE_WRITER_H

#include <fstream>
#include "instruction.h"

class intermeditate_file_writer {
private:
    const std::string FILE_EXTENSION = ".i";
    std::ofstream source_file;

    void write_file_header();
public:
    intermeditate_file_writer(std::string);
    ~intermeditate_file_writer();
    void write(const instruction*);
    void print_sym_table();
};

#endif //SIC_ASSEMBLER_INTERMEDIATE_FILE_WRITER_H
