//
// Created by Ahmed Yakout on 4/24/17.
//

#ifndef SIC_XE_ASSEMBLER_PASS_ONE_H__
#define SIC_XE_ASSEMBLER_PASS_ONE_H__

#include <file_handlers/elementary_file_reader.h>

/**
 * Takes elementary_file_reader and generates intermediate file to be used in pass two.
 * main work of pass one: 
 * - Define symbols.
 * - Assign addresses to all statements.
 * - save the values (addresses) assigned to all labels in sym_table.
 * - perform some processing of assembler directives which is done by handle() method in every directive class.
 */
class pass_one {
private:
    std::unique_ptr<elementary_file_reader> reader;
    std::string path;
    std::string file_name;
public:
	
    pass_one(std::unique_ptr<elementary_file_reader>, std::string _file_path, std::string _file_name);
    /**
     * Starts pass one of assembler.
     */
    void pass();
};

#endif // SIC_XE_ASSEMBLER_PASS_ONE_H__
