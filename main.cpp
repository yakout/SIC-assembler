#include <iostream>
#include <assembler.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << sic_assembler::decimal_to_hex(123);
    return 0;
}