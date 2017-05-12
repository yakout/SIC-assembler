//
// Created by Marwan Tammam on 5/6/17.
//

#ifndef SIC_ASSEMBLER_INTERMEDIATE_FILE_READER_H__
#define SIC_ASSEMBLER_INTERMEDIATE_FILE_READER_H__

#include <file_handlers/file_reader.h>

class intermediate_file_reader: public file_reader {
private:
public:
    intermediate_file_reader(std::string);

    instruction* get_next_instruction();
};

#endif //SIC_ASSEMBLER_INTERMEDIATE_FILE_READER_H__
