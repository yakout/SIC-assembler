//
// Created by Ahmed Yakout on 5/11/17.
//


#include <instruction_factory.h>
#include <directives/end_directive.h>
#include <directives/start_directive.h>
#include <directives/equ_directive.h>
#include <directives/org_directive.h>
#include <directives/ltorg_directive.h>
#include <directives/resw_directive.h>
#include <directives/resb_directive.h>
#include <directives/word_directive.h>
#include <directives/byte_directive.h>
#include <operation.h>


instruction_factory::instruction_factory(std::string buffer): _buffer(buffer) {
}

instruction* instruction_factory::make_instruction(std::string _location, std::string _label, mnemonic* _mnemonic,
                                                     operand* _operand, std::string _comment) {
	instruction* _instruction = nullptr;
    if (*_mnemonic == "word") {
        _instruction = new word_directive(_buffer);
    } else if(*_mnemonic == "byte") {
        _instruction = new byte_directive(_buffer);
    } else if(*_mnemonic == "resw") {
        _instruction = new resw_directive(_buffer);
    } else if(*_mnemonic == "resb") {
        _instruction = new resb_directive(_buffer);
    } else if(*_mnemonic == "equ") {
        _instruction = new equ_directive(_buffer);
    } else if(*_mnemonic == "ltorg") {
        _instruction = new ltorg_directive(_buffer);
    } else if(*_mnemonic == "org") {
        _instruction = new org_directive(_buffer);
    } else if(*_mnemonic == "end") {
        _instruction = new end_directive(_buffer);
    } else if(*_mnemonic == "start") {
        _instruction = new start_directive(_buffer);
    } else {
        _instruction = new operation(_buffer);
    }
    
    _instruction->set_location(_location);
    _instruction->set_label(_label);
    _instruction->set_mnemonic(_mnemonic);
    _instruction->set_operand(_operand);
    _instruction->set_comment(_comment);

    return _instruction;
}
