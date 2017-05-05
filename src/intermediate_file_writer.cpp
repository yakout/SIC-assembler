//
// Created by Ahmed Yakout on 5/4/17.
//

#include <sym_table.h>
#include "intermediate_file_writer.h"

intermeditate_file_writer::intermeditate_file_writer(std::string _path, std::string file_name) {
	source_file.open(_path + file_name + FILE_EXTENSION);
	if (!source_file.is_open()) {
		throw "file failed to open";
	}
    write_file_header();
}

intermeditate_file_writer::~intermeditate_file_writer() {
    source_file.close();
}

void intermeditate_file_writer::write(const instruction * _instruction) {
	// instruction->get_line_number()
}

void intermeditate_file_writer::write_file_header() {
    source_file << "LINE" <<  "SOURCE STAETMENT" << "OBJECT CODE" << "ERROR INDICATOR";
}

void intermeditate_file_writer::print_sym_table() {

}
