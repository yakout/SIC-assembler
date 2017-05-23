//
// Created by Ahmed Yakout on 5/1/17.
//

#ifndef SIC_ASSEMBLER_OBJECT_PROG_WRITER_H__
#define SIC_ASSEMBLER_OBJECT_PROG_WRITER_H__

#include <fstream>
#include <iostream>
#include <instruction.h>

class object_program_writter {
private:
    const std::string HEADER_RECORD_SYMBOL = "H";
    const std::string TEXT_RECORD_SYMBOL = "T";
    const std::string END_RECORD_SYMBOL = "E";
    const std::string FILE_EXTENSION = ".obj";
    const int MAX_TEXT_RECORD_LENGTH = 69;
    const std::string SEPERATOR = "^";
    std::ofstream file;

    // variables for text record
    int current_column_counter = 0;
    std::string current_text_record;
    std::string current_starting_address;
    int current_text_record_length = 0;
    /**
     * this flag is set to true when there is resb, resw directives.
     * this indicates that a space in text record has been allocated
     * and next time if there new object code for other instruction 
     * other than resb, resw just start a new text record.
     */
    bool res_memory_flag = false;

    void reset_text_record();
    void write_text_record();
    void handle_decimal_array(std::string);
public:
    object_program_writter(std::string, std::string);
    ~object_program_writter();
    void write_header_record();
    void write_end_record(int starting_address);
    void add_to_text_record(instruction*);
};

#endif //SIC_ASSEMBLER_OBJECT_PROG_WRITER_H__
