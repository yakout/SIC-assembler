//
// Created by Ahmed Yakout on 5/1/17.
//

#include <assembler.h>
#include <file_handlers/object_program_writter.h>


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

void object_program_writter::write_header_record() {
    std::string program_name = sic_assembler::program_name;
    if (program_name.length() < 7) {
        for (int i = (int) program_name.length(); i < 6; i++) {
            program_name += " ";
        }
    }
    std::string final_header_record = HEADER_RECORD_SYMBOL + SEPERATOR + program_name + SEPERATOR 
                                    + sic_assembler::decimal_to_hex(sic_assembler::starting_address, 6) 
                                    + SEPERATOR + sic_assembler::decimal_to_hex(sic_assembler::program_length, 6);
    // 6 is the length of starting address and program length in header record.
    file << final_header_record << "\n";
}


void object_program_writter::handle_decimal_array(std::string obcode) {
    std::string old_starting_address = current_starting_address;
    int comma_counter = 0;

    for (int i = 0; i < obcode.length(); ++i) {
        if (obcode[i] == ',') {
            comma_counter++;
            obcode[i] = '^';
        }
    }

    int prev = 0;
    for (int i = 0; i < comma_counter + 1; ++i) {
        std::string current_obcode = obcode.substr(prev, 6);
        prev += 7;

        if (current_column_counter + current_obcode.length() > MAX_TEXT_RECORD_LENGTH) {
            // reset counter and initialize new text record;
            write_text_record();
            reset_text_record();
        }
        if (current_starting_address == "") {
            current_starting_address = old_starting_address;
            // todo remove magic numbers
            current_column_counter += 9; // 1 + 6 for starting address + 2 for the length
        }
        current_text_record_length += current_obcode.length() / 2;
        current_text_record += SEPERATOR + current_obcode;
        current_column_counter += current_obcode.length();
    }
}

void object_program_writter::add_to_text_record(instruction* _instruction) {
    if (_instruction->get_operand()->get_type() == operand::operand_type::DECIMAL_ARRAY) {
        handle_decimal_array(_instruction->get_opcode());
        return;
    }
    if (*_instruction->get_mnemonic() == "equ" || *_instruction->get_mnemonic() == "org" 
                            || *_instruction->get_mnemonic() == "ltorg") {
        return;
    }

    // length of current object code.
    int length = _instruction->get_opcode().length();
    if (*_instruction->get_mnemonic() == "resw" || *_instruction->get_mnemonic() == "resb" ) {
        // since the returned object code by 'resb' and 'resw' is "" the length will be 0
        // so we need to make 6 to make sure there is a enough space in text record to make space 
        // for the reserved memory by 'resw' and 'resb'. 
        length = 6;
    }

    if (current_column_counter + length > MAX_TEXT_RECORD_LENGTH) {
        // reset counter and initialize new text record;
        write_text_record();
        reset_text_record();
    }
    if (current_starting_address == "") {
        current_starting_address = _instruction->get_location();
        // todo remove magic numbers
        current_column_counter += 9; // 1 + 6 for starting address + 2 for the length
    }
    if (*_instruction->get_mnemonic() == "resw" || *_instruction->get_mnemonic() == "resb" ) {
        current_text_record += "      "; // make space for reserved memory
        current_column_counter += 6;
    } else {
        current_text_record_length += _instruction->get_opcode().length() / 2;
        current_text_record += SEPERATOR + _instruction->get_opcode();
        current_column_counter += _instruction->get_opcode().length();
    }
}

void object_program_writter::write_text_record() {
    file << TEXT_RECORD_SYMBOL << SEPERATOR << std::setfill('0') << std::setw(6) << current_starting_address 
         << SEPERATOR << std::setw(2) << sic_assembler::decimal_to_hex(current_text_record_length) 
         << current_text_record << "\n";
}

void object_program_writter::reset_text_record() {
    current_column_counter = 0;
    current_text_record = "";
    current_starting_address = "";
    current_text_record_length = 0;
}

void object_program_writter::write_end_record(int starting_address) {
    if (current_text_record != "") {
        write_text_record();
    }
    reset_text_record();
    std::string final_record = END_RECORD_SYMBOL + SEPERATOR + sic_assembler::decimal_to_hex(starting_address, 6);
    file << final_record << "\n";
}
