//
// Created by Ahmed Yakout on 5/4/17.
//

#include <sym_table.h>
#include "intermediate_file_writer.h"

intermeditate_file_writer::intermeditate_file_writer(std::string _path): source_file(_path) {
    write_file_header();
}

intermeditate_file_writer::~intermeditate_file_writer() {
    source_file.close();
}

void intermeditate_file_writer::write(const instruction * _instruction) {
}

void intermeditate_file_writer::write_file_header() {
    source_file << "Loc" <<  "source statement" << "object code" << "error indicator";
}

void intermeditate_file_writer::print_sym_table() {

}
