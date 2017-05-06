//
// Created by Marwan Tammam on 5/6/17.
//

#ifndef SIC_ASSEMBLER_ELEMENTARY_FILE_READER_H
#define SIC_ASSEMBLER_ELEMENTARY_FILE_READER_H

#include "file_reader.h"

class elementary_file_reader: public file_reader {
private:
public:
    elementary_file_reader(std::string);

    instruction *get_next_instruction();
};


#endif //SIC_ASSEMBLER_ELEMENTARY_FILE_READER_H
