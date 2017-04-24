cmake_minimum_required(VERSION 3.6)
project(SIC_XE_assembler)

set(CMAKE_CXX_STANDARD 11)

include_directories( "include" )
set(SOURCE_FILES main.cpp include/instruction.h include/mnemonic.h src/mnemonic.cpp include/op_table.h src/instruction.cpp src/op_table.cpp include/operand.h src/operand.cpp)
add_executable(SIC_XE_assembler ${SOURCE_FILES})