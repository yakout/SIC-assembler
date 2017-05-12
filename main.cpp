#include <iostream>
#include <assembler_driver.h>

void split_extension(const std::string& str,std::string& name, std::string& extension) {
    std::size_t found = str.find_last_of(".");
    name = str.substr(0, found);
    extension = str.substr(found + 1);
}

/**
 * takes full file path and split it into path, name, extension and store them in the given parameters.
 * @param str: the original string 
 * @param path: will store the file path.
 * @param name: will store the file name.
 * @param extension: will store the file extension.
 */         
void split_file_name(const std::string& str, std::string& path, std::string& name, std::string& extension) {
    std::size_t found = str.find_last_of("/\\");
    path = str.substr(0, found + 1); // +1 to take the seperator with the path
    split_extension(str.substr(found + 1), name, extension);
}

/**
 * Method to check the type of OS
 * __WIN32 macro checks both win32 and win64
 * Usefull tip:
 * http://web.archive.org/web/20160306052035/http://nadeausoftware.com/articles/2012/01/c_c_tip_how_use_compiler_predefined_macros_detect_operating_system
 */
void check_os() {
    #if defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
        // UNIX STYLE OS
        std::cout << "This is UNIX sytle OS" << std::endl;
        // do something
    #elif defined(__WIN32) 
        // __WIN32 check for both 32 and 64 so no need to check for for __WIN64
        std::cout << "This is Windows OS" << std::endl;
        // do something
    #endif
}

int main(int argc, char **argv) {
    // check_os();
    std::string file_name;
    std::string path;
    std::string extension;

    // if no argument is passed
    if (argc <= 1) {
       std::cout << "please spicify file as argument" << std::endl; 
       return 0;
    }

    split_file_name(std::string(argv[1]), path, file_name, extension);
    if (extension != "asm") {
       std::cout << "no valid file specified, must be .asm file" << std::endl;
       return 0;
    }

    assembler_driver assembler(path, file_name);
    assembler.assemble();

    return 0;
}