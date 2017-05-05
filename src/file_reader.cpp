//
// Created by Marwan Tammam on 4/30/17.
//


#include <assembler.h>
#include <file_reader.h>
#include <regex_patterns.h>

file_reader::file_reader(std::string path) {
    source_file.open(path);
    if (!source_file.is_open()) {
        throw "error: file not found";
    }
}


file_reader::~file_reader() {
    source_file.close();
}

bool file_reader::is_comment_line() {
    return file_reader::buffer[0] == '.';
}

bool file_reader::has_next_instruction() {
    if (is_comment_line()) {
        buffer.clear();
    }
    if (buffer.length() > 0) {
        return true;
    }
    if (getline(file_reader::source_file, file_reader::buffer)) {
        current_line_number++;
        #if defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
            // UNIX STYLE OS
            buffer = buffer.substr(0, buffer.length() - 1);
        #elif defined(__WIN32) 
            // __WIN32 check for both 32 and 64 so no need to check for for __WIN64
            buffer = buffer.substr(0, buffer.length() - 2);
        #endif
        buffer = sic_assembler::to_lower(buffer);
        buffer = sic_assembler::remove_tabs(buffer);
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
//    std::cout << buffer << std::endl;
    std::smatch matches;
    instruction *_instruction = new instruction(buffer);
    _instruction->set_line_number(current_line_number);
    try {
        if (regex_search(buffer, matches, std::regex(INSTRUCTION_WITH_COMMENT))) {
            _instruction->set_label(matches[1].str());
            _instruction->set_mnemonic(new mnemonic(matches[2].str()));
            _instruction->set_operand(new operand(matches[3].str()));
            _instruction->set_comment(matches[4]);
        } else if (regex_search(buffer, matches, std::regex(INSTRUCTION_WITHOUT_COMMENT))) {
            _instruction->set_label(matches[1].str());
            _instruction->set_mnemonic(new mnemonic(matches[2].str()));
            _instruction->set_operand(new operand(matches[3].str()));
        } else if (regex_search(buffer, matches, std::regex(INSTRUCTION_WITHOUT_OPERAND_WITH_COMMENT))) {
            _instruction->set_label(matches[1].str());
            _instruction->set_mnemonic(new mnemonic(matches[2].str()));
            _instruction->set_comment(matches[3]);
        } else if (regex_search(buffer, matches, std::regex(INSTRUCTION_WITHOUT_OPERAND_WITHOUT_COMMENT))) {
            _instruction->set_label(matches[1].str());
            _instruction->set_mnemonic(new mnemonic(matches[2].str()));
        } else {
            throw "Invalid instruction format";
        }
    } catch (const char *error_msg) {
        throw error_msg;
    }
    buffer.clear();
    return _instruction;
}



