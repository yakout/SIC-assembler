//
// Created by Ahmed Yakout on 5/1/17.
//



#include <sym_table.h>
#include <op_table.h>
#include <pass_two.h>
#include <object_program_writter.h>
#include <assembler.h>

pass_two::pass_two(file_reader *_reader) {
    reader = _reader;
}

void pass_two::pass() {
    object_program_writter writer("./", "tests/valid_test1");
    std::ofstream listing_file;
    std::string path = "./tests/valid_test1_list_file.txt";
    listing_file.open(path, std::ios_base::app);
    if (!listing_file.is_open()) {
        throw "failed to open file";
    }

    listing_file << ">>    S T A R T     O F     P A S S  II \n";
    listing_file << ">>   *****************************************************\n\n";
    listing_file << ">>   A s s e m b l e d    p r o g r a m     l i s t i n g\n\n";
    listing_file << " Object Code         Source Statement\n";
    listing_file << "---------------------------------------------\n";

    instruction* next_instruction = reader->get_next_instruction();

    if (*next_instruction->get_mnemonic() == "start") {
        writer.write_header_record(next_instruction->get_label());
        listing_file << std::setw(21) << ""  << next_instruction->get_full_instruction() << "\n";
    }
    while(reader->has_next_instruction()) {
        next_instruction = reader->get_next_instruction();
        if (*next_instruction->get_mnemonic() == "end") {
            break;
        }
        if (op_table::get_instance()->lookup(next_instruction->get_mnemonic()->get_name())) {
            if (next_instruction->has_operand()
                && next_instruction->get_operand()->get_type() == operand::operand_type::LABEL) {
                if (sym_table::get_instance()->lookup(next_instruction->get_operand()->get_name())) {
                    // we set the operand address as the symbol value from sym_table
                } else {
                    // we set the operand address = 0
                    // set error flag
                }
            }
        } else { // directive
            if (*next_instruction->get_mnemonic() != "byte"
                    && *next_instruction->get_mnemonic() != "word") {
                continue;
            }
        }
        std::cout << next_instruction->get_opcode() << std::endl;
        listing_file << std::setw(6) << next_instruction->get_opcode() << std::setw(15) << "" << next_instruction->get_full_instruction() << "\n";
        writer.add_to_text_record(next_instruction);
    }
    writer.write_end_record(sic_assembler::starting_address);
    listing_file << "\n>>    s u c c e s s f u l    a s s e m b l y\n";
    listing_file.close();
}
