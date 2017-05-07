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

std::string file_reader::get_buffer() {
    return buffer;
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
        // since in unix systems the end of string is followed by \r wheres in windows it's \r\n
        // we should remove them if they exist.
        while (buffer.back() == '\r' || buffer.back() == '\n') {
            buffer.pop_back();
        }
        buffer = sic_assembler::to_lower(buffer);
        buffer = sic_assembler::remove_tabs(buffer);
        return true;
    } else {
        buffer.clear();
        return false;
    }
}

instruction *file_reader::get_next_instruction() { return nullptr; }



