cmake_minimum_required(VERSION 3.6)
project(SIC_assembler)

set(CMAKE_CXX_STANDARD 11)

include_directories( "include" )
set(SOURCE_FILES main.cpp include/instruction.h include/mnemonic.h src/mnemonic.cpp include/op_table.h
        src/instruction.cpp src/op_table.cpp include/operand.h src/operand.cpp include/pass_one.h include/pass_two.h
        include/sym_table.h src/pass_one.cpp include/assembler.h src/sym_table.cpp src/pass_two.cpp src/temp.cpp
        include/file_reader.h src/file_reader.cpp include/regex_patterns.h include/object_program_writter.h src/object_program_writter.cpp src/assembler.cpp include/lit_table.h src/lit_table.cpp include/intermediate_file_writer.h src/intermediate_file_writer.cpp include/intermediate_file_reader.h include/elementary_file_reader.h src/elementary_file_reader.cpp src/intermediate_file_reader.cpp)
add_executable(SIC_assembler ${SOURCE_FILES})