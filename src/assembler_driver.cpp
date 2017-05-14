//
// Created by Ahmed Yakout on 5/9/17.
//


#include <assembler_driver.h>
#include <pass_one.h>
#include <pass_two.h>
#include <file_handlers/elementary_file_reader.h>
#include <file_handlers/intermediate_file_reader.h>
#include <errors/pass_one/pass_one_error.h>
#include <errors/pass_two/pass_two_error.h>
#include <utils.h>

const std::string assembler_driver::SOURCE_FILE_EXTENSION = ".asm";
const std::string assembler_driver::LISTING_FILE_EXTENSION = "_listing.txt";
const std::string assembler_driver::ITERMEDIATE_FILE_EXTENSION = "_intermediate.txt";

assembler_driver::assembler_driver(std::string path, std::string name): file_name(name), file_path(path) {

}

assembler_driver::~assembler_driver() {

}

void assembler_driver::assemble() {
    bool pass_one_faild = true;
	try {
        auto reader = utils::make_unique<elementary_file_reader>(file_path + file_name 
                                                                    + SOURCE_FILE_EXTENSION);
        pass_one passOne(std::move(reader), file_path, file_name);
        passOne.pass();
        pass_one_faild = false;
    } catch (const char* e) {
        // may be caused when trying to open files.
    	std::cout << e << std::endl;
    }

    if (pass_one_faild) {
        return;
    }

	try {
        auto reader = utils::make_unique<intermediate_file_reader>(file_path + file_name 
                                                                    + ITERMEDIATE_FILE_EXTENSION);
        pass_two passTwo(std::move(reader), file_path, file_name);    
        passTwo.pass();
    } catch(const pass_two_error& e) {
        // may be caused by undefined errors.
		std::cout << e.what() << std::endl;
    } catch (const char* e) {
        // may be caused when trying to open files.
        std::cout << e << std::endl;
    }
}