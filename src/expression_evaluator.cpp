//
// Created by Ahmed Yakout on 5/14/17.
//


#include <expression_evaluator.h>
#include <errors/invalid_expression.h>
#include <operand.h>
#include <assembler.h>

expression_evaluator::expression_evaluator(std::string exp): expression(exp) {

}

expression_evaluator::~expression_evaluator() {

}

std::string expression_evaluator::evaluate() {
    std::string address;
    int f = 0;
    std::string a;
    std::string b;
    for (int i = 0; i < expression.length(); i++){
        if (expression[i] == '+'){
            f = 1;
        }
        else if (expression[i] == '-'){
            f = -1;
        }
        if (f != 0) {
            a = expression.substr(0, i);
            b = expression.substr(i+1, expression.length() - i);
            break;
        }
    }
    if (f != 0) {
        operand *u = new operand(a);
        operand *v = new operand(b);
        if (u->get_type() != operand::operand_type::DECIMAL && u->get_type() != operand::operand_type::LABEL 
                                                && u->get_type() != operand::operand_type::LOC_COUNTER) {
            delete u;
            delete v;
            throw invalid_expression();
        }
        if (v->get_type() != operand::operand_type::DECIMAL && v->get_type() != operand::operand_type::LABEL 
                                                && u->get_type() != operand::operand_type::LOC_COUNTER) {
            delete u;
            delete v;
            throw invalid_expression();
        }

        // evaluating
        if (u->get_type() == operand::operand_type::LOC_COUNTER) {
            if (v->get_type() != operand::operand_type::LOC_COUNTER) {
                address = sic_assembler::decimal_to_hex(sic_assembler::location_counter
                                + f * sic_assembler::hex_to_int(v->get_address()), operand::OPERAND_WIDTH);
            } else {
                delete u;
                delete v;
                throw invalid_expression();   
            }
        } else if (v->get_type() == operand::operand_type::LOC_COUNTER) {
                address = sic_assembler::decimal_to_hex(sic_assembler::hex_to_int(u->get_address()) 
                                + f * sic_assembler::location_counter, operand::OPERAND_WIDTH);
        } else {
            address = sic_assembler::decimal_to_hex(sic_assembler::hex_to_int(u->get_address()) 
                                + f * sic_assembler::hex_to_int(v->get_address()), operand::OPERAND_WIDTH);
        }
        delete u;
        delete v;
    } else {
        throw invalid_expression();
    }
    return address;
}