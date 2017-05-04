//
// Created by Marwan Tammam on 4/30/17.
//


#include "file_reader.h"
#include "regex_patterns.h"

file_reader::file_reader() {
}

bool file_reader::is_comment_line() {
    return file_reader::buffer[0] == '.';
}

bool file_reader::has_next_instruction() {
    if (file_reader::buffer.length() != 0) {
        return true;
    }
    if (getline(file_reader::source_file, file_reader::buffer)) {
        return true;
    } else {
        buffer.clear();
        return false;
    }
}

instruction *file_reader::get_next_instruction() {
    if (!file_reader::has_next_instruction()) {
        return nullptr;
    }
    if (file_reader::is_comment_line()) {
        return file_reader::get_next_instruction();
    }
    std::smatch matches;
    instruction *instruction;
    try {
        if (regex_search(buffer, matches, std::regex(INSTRUCTION_WITH_COMMENT))) {
            instruction->set_label(matches[1].str());
            instruction->set_mnemonic(new mnemonic(matches[2].str()));
            instruction->set_operand(new operand(matches[3].str()));
            instruction->set_comment(matches[4]);
        } else if (regex_search(buffer, matches, std::regex(INSTRUCTION_WITHOUT_COMMENT))) {
            instruction->set_label(matches[1].str());
            instruction->set_mnemonic(new mnemonic(matches[2].str()));
            instruction->set_operand(new operand(matches[3].str()));
        } else if (regex_search(buffer, matches, std::regex(INSTRUCTION_WITHOUT_OPERAND_WITH_COMMENT))) {
            instruction->set_label(matches[1].str());
            instruction->set_mnemonic(new mnemonic(matches[2].str()));
            instruction->set_comment(matches[3]);
        } else if (regex_search(buffer, matches, std::regex(INSTRUCTION_WITHOUT_OPERAND_WITHOUT_COMMENT))) {
            instruction->set_label(matches[1].str());
            instruction->set_mnemonic(new mnemonic(matches[2].str()));
        } else {
            throw "Invalid instruction format";
        }
    }
    catch (const char *error_msg) {
        throw error_msg;
    }
    buffer.clear();
    return nullptr;
}



