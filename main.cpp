#include <iostream>
#include <pass_one.h>
#include "assembler.h"

int main() {
    file_reader* fileReader;
    try {
        fileReader = new file_reader("../tests/valid_test1.txt");
    } catch (const char *error_msg) {
        std::cout << error_msg << std::endl;
    }

    pass_one passOne(fileReader);

    try {
        passOne.pass();
    } catch (const std::string e) {
        std::cout << e << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }

//    std::ifstream file;
//    file.open("../tests/valid_test1.txt");
//    std::cout << file.is_open() << std::endl;
//    std::string line;
//    getline(file, line);
//    std::cout << line << std::endl;

    std::cout << "****************************" << std::endl;
    std::cout << sic_assembler::decimal_to_hex(123) << std::endl;
    std::cout << sic_assembler::hex_to_int("EF") << std::endl;
    std::cout << "Loc" << std::setw(20) <<  "source statement"
              << std::setw(30) << "object code" << std::setw(30) << "error indicator";
    return 0;
}