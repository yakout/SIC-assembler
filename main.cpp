#include <iostream>
#include <pass_one.h>
#include <pass_two.h>
#include <assembler.h>
#include "elementary_file_reader.h"



void split_extension(const std::string& str,std::string& name, std::string& extension) {
    std::size_t found = str.find_last_of(".");
    name = str.substr(0, found);
    extension = str.substr(found + 1);
}

// takes full file path and split it into path + name given as parameters.
void split_file_name(const std::string& str, std::string& path, std::string& name, std::string& extension) {
    std::size_t found = str.find_last_of("/\\");
    path = str.substr(0, found + 1); // +1 to take the seperator with the path
    split_extension(str.substr(found + 1), name, extension);
}

int main(int argc, char **argv) {
    std::string file_name;
    std::string path;
    std::string extension;
    split_file_name(std::string(argv[1]), path, file_name, extension);
    if (extension != "asm") {
        std::cout << "no valid file specified, must be .asm file" << std::endl;
        return 0;
    }

    file_reader* fileReader;
    try {
        fileReader = new elementary_file_reader(path + file_name + "." + extension); // "./tests/valid_test1.asm"
    } catch (const char *error_msg) {
        std::cout << error_msg << std::endl;
        return 0;
    }

    file_reader* fileReader2;
    try {
        fileReader2 = new elementary_file_reader(path + file_name + "." + extension);
    } catch (const char *error_msg) {
        std::cout << error_msg << std::endl;
        return 0;
    }

    pass_one passOne(fileReader, path, file_name);
    pass_two passTwo(fileReader2, path, file_name);

    try {
        passOne.pass();
        delete fileReader;
        passTwo.pass();
        delete fileReader2;
    } catch (const std::string e) {
        std::cout << e << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }

    return 0;
}