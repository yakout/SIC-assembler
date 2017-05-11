//
// Created by Marwan Tammam on 5/6/17.
//

#include <regex_patterns.h>
#include <assembler.h>
#include <null_instruction.h>
#include <file_handlers/intermediate_file_reader.h>
#include <errors/pass_one/invalid_instruction_format.h>
#include <errors/assembler_error.h>
#include <instruction_factory.h>

intermediate_file_reader::intermediate_file_reader(std::string path): file_reader(path) {

}

instruction* intermediate_file_reader::get_next_instruction() {
    if (!intermediate_file_reader::has_next_instruction()) {
        return new null_instruction();
    }
    if (intermediate_file_reader::is_comment_line()) {
        return intermediate_file_reader::get_next_instruction();
    }

    // std::cout << buffer << std::endl;
    std::smatch matches;
    std::string _location = "";
    std::string _label = "";
    mnemonic* _mnemonic = nullptr;
    operand* _operand = nullptr;
    std::string _comment = "";
    try {
        if (regex_search(intermediate_file_reader::buffer, matches, std::regex(LC_INSTRUCTION_WITH_COMMENT))) {
            _location = matches[1].str();
            _label = matches[2].str();
            _mnemonic = new mnemonic(matches[3].str());
            _operand = new operand(matches[4].str());
            _comment = matches[5].str();
        } else if (regex_search(intermediate_file_reader::buffer, matches, std::regex(LITERAL_FORMAT))) {
            buffer.clear();
            return intermediate_file_reader::get_next_instruction();
        } else if (regex_search(intermediate_file_reader::buffer, matches, std::regex(LC_INSTRUCTION_WITHOUT_COMMENT))) {
            _location = matches[1].str();
            _label = matches[2].str();
            _mnemonic = new mnemonic(matches[3].str());
            _operand = new operand(matches[4].str());
        } else if (regex_search(intermediate_file_reader::buffer, matches, std::regex(LC_INSTRUCTION_WITHOUT_OPERAND_WITH_COMMENT))) {
            _location = matches[1].str();
            _label = matches[2].str();
            _mnemonic = new mnemonic(matches[3].str());
            _comment = matches[4].str();
            _operand = new operand("");
        } else if (regex_search(intermediate_file_reader::buffer, matches, std::regex(LC_INSTRUCTION_WITHOUT_OPERAND_WITHOUT_COMMENT))) {
            _location = matches[1].str();
            _label = matches[2].str();
            _mnemonic = new mnemonic(matches[3].str());
            _operand = new operand("");
        } else {
            throw invalid_instruction_format();
        }

        instruction_factory f(buffer);
        buffer.clear();

        return f.make_instruction(_location, _label, _mnemonic, _operand, _comment);
    } catch (const assembler_error& e) {
        buffer.clear();
        throw;
    }
}
