//
// Created by Marwan Tammam on 5/6/17.
//

#include <regex_patterns.h>
#include <assembler.h>
#include <file_handlers/intermediate_file_reader.h>
#include <errors/pass_one/invalid_instruction_format.h>

intermediate_file_reader::intermediate_file_reader(std::string path): file_reader(path) {

}

instruction* intermediate_file_reader::get_next_instruction() {
    if (!intermediate_file_reader::has_next_instruction()) {
        return nullptr;
    }
    if (intermediate_file_reader::is_comment_line()) {
        return intermediate_file_reader::get_next_instruction();
    }

    // std::cout << buffer << std::endl;
    std::smatch matches;
    instruction* _instruction = new instruction(buffer);
    _instruction->set_line_number(current_line_number);
    try {
        if (regex_search(intermediate_file_reader::buffer, matches, std::regex(LC_INSTRUCTION_WITH_COMMENT))) {
            _instruction->set_location(matches[1].str());
            _instruction->set_label(matches[2].str());
            _instruction->set_mnemonic(new mnemonic(matches[3].str()));
            _instruction->set_operand(new operand(matches[4].str()));
            _instruction->set_comment(matches[5].str());
        } else if (regex_search(intermediate_file_reader::buffer, matches, std::regex(LC_INSTRUCTION_WITHOUT_COMMENT))) {
            _instruction->set_location(matches[1].str());
            _instruction->set_label(matches[2].str());
            _instruction->set_mnemonic(new mnemonic(matches[3].str()));
            _instruction->set_operand(new operand(matches[4].str()));
        } else if (regex_search(intermediate_file_reader::buffer, matches, std::regex(LC_INSTRUCTION_WITHOUT_OPERAND_WITH_COMMENT))) {
            _instruction->set_location(matches[1].str());
            _instruction->set_label(matches[2].str());
            _instruction->set_mnemonic(new mnemonic(matches[3].str()));
            _instruction->set_comment(matches[4].str());
            _instruction->set_operand(new operand(""));
        } else if (regex_search(intermediate_file_reader::buffer, matches, std::regex(LC_INSTRUCTION_WITHOUT_OPERAND_WITHOUT_COMMENT))) {
            _instruction->set_location(matches[1].str());
            _instruction->set_label(matches[2].str());
            _instruction->set_mnemonic(new mnemonic(matches[3].str()));
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
