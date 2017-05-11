//
// Created by Marwan Tammam on 5/6/17.
//

#include <regex_patterns.h>
#include <assembler.h>
#include <null_instruction.h>
#include <file_handlers/elementary_file_reader.h>
#include <errors/pass_one/invalid_instruction_format.h>
#include <errors/pass_one/operand_out_of_range.h>
#include <errors/assembler_error.h>
#include <instruction_factory.h>

elementary_file_reader::elementary_file_reader(std::string path) : file_reader(path) {

}

instruction* elementary_file_reader::get_next_instruction() {
    if (!elementary_file_reader::has_next_instruction()) {
        return new null_instruction();
    }
    if (elementary_file_reader::is_comment_line()) {
        buffer.clear();
        return elementary_file_reader::get_next_instruction();
    }
    std::smatch matches;
    std::string _label = "";
    mnemonic* _mnemonic = nullptr;
    operand* _operand = nullptr;
    std::string _comment = "";
    try {
        if (regex_search(elementary_file_reader::buffer, matches, std::regex(INSTRUCTION_WITH_COMMENT))) {
            _label = matches[1].str();
            _mnemonic = new mnemonic(matches[2].str());
            _operand = new operand(matches[3].str());
            _comment = matches[4].str();
        } else if (regex_search(elementary_file_reader::buffer, matches, std::regex(INSTRUCTION_WITHOUT_COMMENT))) {
            _label = matches[1].str();
            _mnemonic = new mnemonic(matches[2].str());
            _operand = new operand(matches[3].str());
        } else if (regex_search(elementary_file_reader::buffer, matches, std::regex(INSTRUCTION_WITHOUT_OPERAND_WITH_COMMENT))) {
            _label = matches[1].str();
            _mnemonic = new mnemonic(matches[2].str());
            _comment = matches[3].str();
            _operand = new operand("");
        } else if (regex_search(elementary_file_reader::buffer, matches, std::regex(INSTRUCTION_WITHOUT_OPERAND_WITHOUT_COMMENT))) {
            _label = matches[1].str();
            _mnemonic = new mnemonic(matches[2].str());
            _operand = new operand("");
        } else {
            throw invalid_instruction_format();
        }

        instruction_factory f(buffer);
        buffer.clear();

        return f.make_instruction("", _label, _mnemonic, _operand, _comment);
    } catch (const assembler_error& e) {
        buffer.clear();
        throw;
    } catch (const std::out_of_range& e) {
        // out of range my be thrown from std:
        buffer.clear();
        throw operand_out_of_range();
    }
}
