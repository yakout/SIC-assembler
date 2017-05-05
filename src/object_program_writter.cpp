//
// Created by Ahmed Yakout on 5/1/17.
//

#include "assembler.h"
#include "object_program_writter.h"


object_program_writter::object_program_writter(std::string path, std::string file_name) {
    file.open(path + file_name + FILE_EXTENSION);
    if (!file.is_open()) {
        throw "failed to create file";
    }
}

object_program_writter::~object_program_writter() {
    // RAII
    file.close();
}

void object_program_writter::write_header_record(std::string program_name) {
    if (program_name.length() < 7) { // todo remove magic numbers
        for (int i = (int) program_name.length(); i < 6; i++) { // todo remove magic numbers
            program_name += " ";
        }
    }
    std::string final_header_record = HEADER_RECORD_SYMBOL + SEPERATOR + program_name + SEPERATOR 
                                        + sic_assembler::decimal_to_hex(sic_assembler::starting_address, 6) 
                                        + SEPERATOR + sic_assembler::decimal_to_hex(sic_assembler::program_length, 6); // todo remove magic numbers
    file << final_header_record << "\n";
}


void object_program_writter::add_to_text_record(instruction* _instruction) {
    if (current_column_counter >= MAX_TEXT_RECORD_LENGTH) {
        // reset counter and initialize new text record;
        reset_text_record();
        write_text_record();
    }
    if (current_starting_address == "") {
        current_starting_address = _instruction->get_location();
        // todo remove magic numbers
        current_column_counter += 9; // 1 + 6 for starting address + 2 for the length
    }
    current_text_record_length += _instruction->get_opcode().length() / 2;
    current_text_record += SEPERATOR + _instruction->get_opcode();
    current_column_counter += _instruction->get_opcode().length();
}

void object_program_writter::write_text_record() {
    std::string final_text_record = TEXT_RECORD_SYMBOL + current_starting_address
                                    + std::to_string(current_text_record_length) + current_text_record;
    file << final_text_record << "\n";
}

void object_program_writter::reset_text_record() {
    current_column_counter = 0;
    current_text_record = "";
    current_starting_address = "";
    current_text_record_length = 0;
}

void object_program_writter::write_end_record(int starting_address) {
    std::string final_record = END_RECORD_SYMBOL + SEPERATOR + sic_assembler::decimal_to_hex(starting_address, 6); // todo remove magic numbers
    file << final_record << "\n";
}

