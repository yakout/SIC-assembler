//
// Created by Ahmed Yakout on 4/24/17.
//

#ifndef SIC_ASSEMBLER_PASS_TWO_H__
#define SIC_ASSEMBLER_PASS_TWO_H__

#include <file_handlers/intermediate_file_reader.h>

/**
 * pass two class takes intermediate_file_reader and generates object program for given assembly code.
 * main work of pass two:
 * -  
 */
class pass_two {
private:
    std::unique_ptr<intermediate_file_reader> reader;
    std::string path;
    std::string file_name;
public:

    pass_two(std::unique_ptr<intermediate_file_reader>, std::string _file_path, std::string _file_name);
    /**
     * Starts pass two of the assembler.
     */
    void pass();
};

#endif // SIC_ASSEMBLER_PASS_TWO_H__
