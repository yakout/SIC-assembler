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

const std::string assembler_driver::SOURCE_FILE_EXTENSION = ".asm";
const std::string assembler_driver::LISTING_FILE_EXTENSION = "_listing.txt";
const std::string assembler_driver::ITERMEDIATE_FILE_EXTENSION = "_intermediate.txt";

assembler_driver::assembler_driver(std::string path, std::string name): file_name(name), file_path(path) {

}

assembler_driver::~assembler_driver() {

}

void assembler_driver::assemble() {
	try {
        std::unique_ptr<file_reader> reader1(new elementary_file_reader(file_path + file_name + SOURCE_FILE_EXTENSION));
        pass_one passOne(std::move(reader1), file_path, file_name);
        passOne.pass();
    } catch (const pass_one_error& e) {
    	std::cout << e.what() << std::endl;
    } catch (const char *e) {
    	std::cout << e << std::endl;
    } catch (const std::string e) {
    	std::cout << e << std::endl;
    }

	try {
        std::unique_ptr<file_reader> reader2(new intermediate_file_reader(file_path + file_name 
        	+ ITERMEDIATE_FILE_EXTENSION));
        pass_two passTwo(std::move(reader2), file_path, file_name);    
        passTwo.pass();
    } catch(const pass_two_error& e) {
		std::cout << e.what() << std::endl;
    } catch (const std::string e) {
        std::cout << e << std::endl;
    } catch (const char* e) {
        std::cout << e << std::endl;
    }
}