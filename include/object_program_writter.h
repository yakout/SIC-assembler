//
// Created by Ahmed Yakout on 5/1/17.
//

#ifndef SIC_ASSEMBLER_OBJECT_PROG_WRITER_H
#define SIC_ASSEMBLER_OBJECT_PROG_WRITER_H

#include <fstream>
#include "iostream"
#include "instruction.h"

class object_program_writter {
private:
    const std::string HEADER_RECORD_SYMBOL = "H";
    const std::string TEXT_RECORD_SYMBOL = "T";
    const std::string END_RECORD_SYMBOL = "E";
    const std::string FILE_EXTENSION = ".o";
    const int MAX_TEXT_RECORD_LENGTH = 69;
    const std::string SEPERATOR = "^";
    std::ofstream file;

    // variables for text record
    int current_column_counter = 0;
    std::string current_text_record;
    std::string current_starting_address;
    int current_text_record_length = 0;

    void reset_text_record();
public:
    object_program_writter(std::string, std::string);
    ~object_program_writter();
    void write_header_record(std::string program_name);
    void write_text_record();
    void write_end_record(int starting_address);
    void add_to_text_record(instruction*);
};

#endif //SIC_ASSEMBLER_OBJECT_PROG_WRITER_H
