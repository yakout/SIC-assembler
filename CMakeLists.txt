cmake_minimum_required(VERSION 3.6)
project(SIC_assembler)

set(CMAKE_CXX_STANDARD 11)

include_directories( "include" )
set(SOURCE_FILES main.cpp src/mnemonic.cpp src/instruction.cpp src/tables/op_table.cpp src/operand.cpp 
		 src/pass_one.cpp  src/tables/sym_table.cpp src/pass_two.cpp
         src/file_handlers/file_reader.cpp src/file_handlers/object_program_writter.cpp src/assembler.cpp src/tables/lit_table.cpp src/file_handlers/elementary_file_reader.cpp src/file_handlers/intermediate_file_reader.cpp
         src/errors/assembler_error.cpp src/errors/pass_one/pass_one_error.cpp src/errors/pass_one/duplicate_start_directive.cpp src/errors/pass_one/duplicate_end_directive.cpp src/errors/pass_one/duplicate_symbol.cpp src/errors/pass_one/invalid_instruction_format.cpp src/errors/pass_one/missing_end_directive.cpp src/errors/pass_one/missing_start_directive.cpp src/errors/pass_two/pass_two_error.cpp src/errors/pass_two/undefined_symbol.cpp src/errors/pass_one/invalid_forward_reference.cpp
         src/errors/pass_one/invalid_combination.cpp src/errors/pass_one/invalid_label.cpp src/errors/pass_two/invalid_expression.cpp
         src/errors/pass_one/invalid_mnemonic.cpp src/errors/pass_one/invalid_operand.cpp src/errors/pass_one/operand_out_of_range.cpp src/assembler_driver.cpp src/operation.cpp src/null_instruction.cpp src/instruction_factory.cpp
         src/directives/start_directive.cpp src/directives/end_directive.cpp src/directives/word_directive.cpp src/directives/byte_directive.cpp src/directives/resw_directive.cpp src/directives/resb_directive.cpp src/directives/equ_directive.cpp src/directives/org_directive.cpp src/directives/ltorg_directive.cpp)
         
add_executable(SIC_assembler ${SOURCE_FILES})