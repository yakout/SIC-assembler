//
// Created by Ahmed Yakout on 5/1/17.
//

#include "object_program_writter.h"


object_program_writter::object_program_writter() {
    file.open (path + file_name + FILE_EXTENSION);
}

object_program_writter::~object_program_writter() {
    // RAII
    file.close();
}

void object_program_writter::reset_text_record() {
    current_column_counter = 0;
    current_text_record = "";
    current_starting_address = "";
    current_text_record_length = 0;
}

void object_program_writter::write_header_record(std::string program_name, std::string starting_address,
                                                 std::string program_length) {
    if (program_name.length() < 7) {
        for (int i = (int) program_name.length(); i < 6; i++) {
            program_name += " ";
        }
    }
    std::string final_header_record = HEADER_RECORD_SYMBOL + program_name + starting_address + program_length;
    file << final_header_record << "\n";
}

void object_program_writter::write_text_record() {
    std::string final_text_record = TEXT_RECORD_SYMBOL + current_starting_address
                                    + current_text_record_length + current_text_record;
    file << final_text_record << "\n";
}

void object_program_writter::add_to_text_record(const instruction* instruction) {
    if (current_column_counter == MAX_TEXT_RECORD_LENGTH) {
        // reset counter and initialize new text record;
        reset_text_record();
        write_text_record();
    }
    if (current_starting_address == "") {
//        current_starting_address = instruction->get_address();
        current_column_counter += 9; // 1 + 6 for starting address + 2 for the length
    }
//    current_text_record_length += instruction->get_object_code().length() / 2;
//    current_text_record += instruction->get_object_code();
//    current_column_counter += instruction->get_object_code().length();
}

void object_program_writter::write_end_record(std::string starting_address) {
    std::string final_record = END_RECORD_SYMBOL + starting_address;
    file << final_record << "\n";
}


