//
// Created by Marwan Tammam on 5/6/17.
//

#include "regex_patterns.h"
#include "assembler.h"
#include "elementary_file_reader.h"

elementary_file_reader::elementary_file_reader(std::string path) : file_reader(path){}

instruction *elementary_file_reader::get_next_instruction() {
    if (!elementary_file_reader::has_next_instruction()) {
        return nullptr;
    }
    if (elementary_file_reader::is_comment_line()) {
        return elementary_file_reader::get_next_instruction();
    }
   // std::cout << buffer << std::endl;
    std::smatch matches;
    instruction *_instruction = new instruction(buffer);
    _instruction->set_line_number(current_line_number);
    try {
        if (regex_search(elementary_file_reader::buffer, matches, std::regex(INSTRUCTION_WITH_COMMENT))) {
            _instruction->set_label(matches[1].str());
            _instruction->set_mnemonic(new mnemonic(matches[2].str()));
            _instruction->set_operand(new operand(matches[3].str()));
            _instruction->set_comment(matches[4].str());
        } else if (regex_search(elementary_file_reader::buffer, matches, std::regex(INSTRUCTION_WITHOUT_COMMENT))) {
            _instruction->set_label(matches[1].str());
            _instruction->set_mnemonic(new mnemonic(matches[2].str()));
            _instruction->set_operand(new operand(matches[3].str()));
        } else if (regex_search(elementary_file_reader::buffer, matches, std::regex(INSTRUCTION_WITHOUT_OPERAND_WITH_COMMENT))) {
            _instruction->set_label(matches[1].str());
            _instruction->set_mnemonic(new mnemonic(matches[2].str()));
            _instruction->set_comment(matches[3].str());
            _instruction->set_operand(new operand(""));
        } else if (regex_search(elementary_file_reader::buffer, matches, std::regex(INSTRUCTION_WITHOUT_OPERAND_WITHOUT_COMMENT))) {
            _instruction->set_label(matches[1].str());
            _instruction->set_mnemonic(new mnemonic(matches[2].str()));
            _instruction->set_operand(new operand(""));
        } else {
            throw "Invalid instruction format";
        }
    } catch (const char *error_msg) {
        buffer.clear();
        throw error_msg;
    }
    buffer.clear();
    return _instruction;
}
