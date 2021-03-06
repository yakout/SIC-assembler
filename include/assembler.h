//
// Created by Ahmed Yakout on 5/1/17.
//

/**
 *   A S S U M P T I O N S
 *
 *   - any hex value must be in the form 0x[hex value]
 *   - empty line are not allowed, all lines must be a valid statement or a comment.
 *   - pass one and two stop reading after finding 'end' directive and will ignore any following instructions.
 *     so if another end directive or any instruction is found later no error will be thrown.
 *   - there is no LC for invalid instructions, and will not be written into intermediate file.
 *   - if there is errors in pass 1 there will be only intermediate file and the obj file will be incorrect.
 *   - no space in expression is allowed
 *   - if there is any error in pass one pass two will not work.
 *   - epression *-* or *+* is not valid.
 *   - in epxression location counter symbol '*' must comes first.
 *   - when resw or resb is incountered in intermediate file we make space for it in object program 
 *     then start a new text record.
 *   - no spaces after end,org.. directives is allowed unless there is comment or valid operand.
 *   - literals that represents addresses (e.g =*) are not supported, since they need modification record.
 */


/**
 *  Features
 *  support array e.g: WORD 1,2,3 
 */

/**
 *  TODO
 *  
 * 
 */

/**
 * DONE
 *    handled forward reference in org and undefined labels in expression evaluator
 *    handled negative values in expression evaluator
 *    
 */


// l i t e r a l s
//                  key in table     value
// LDA  =24         (24)            address assigned
// LDA  =*          (*0)             //
// LDA  =*          (*1)             //
// LDA  =*          (*2)             //
// LDA  =*          (*3)             //
// LDA  =*          (*4)             //
// LDA  =C'EOF'     (X'454f46')      //
// LDA  =X'454F46'  (X'454f46')      //

// e q u
// l1 equ stab+4
// l2 equ stab+12
// l3 equ stab*12
// l4 equ stab/12 division will result in integers values only
// l5 equ *+3

// direvtives
    // org_directive    // Change location counter and throws undefined_symbol if operand symbol not found.
    // ltorg_directive  // put all unassigned literals in interm file
    // equ_directive    // insert in symtable the corresponding value and don't increase lc and throws undifined_symbol error if operand symbol not found
    // end_directive    // check if lit_table has unassigned literals put them in interm file otherwise set the pass_end flag to true  
    // start_directive  // set starting location and program name if exist and initilaize location counter
    // word_directive   // insert in symtable the corresponding value and increase lc by 3
    // byte_directive   // insert in symtable the corresponding value and increase lc by the length of bytes
    // resw_directive   // insert in symtable the corresponding value and increase lc by 3*operand_value
    // resb_directive   // insert in symtable the corresponding value and increase lc by operand_value

// data_types
    // data
    // x_data
    // c_data
    // w_data
    // expression

// tables_data
    // table_data
    // sym_data // abs/relative, address, block number
    // literal_data // length, hex, address 
    // op_data // 

// parsers
    // expression_parser
    // input_parser
    // operand_parser


#ifndef SIC_XE_ASSEMBLER_ASSEMBLER_H__
#define SIC_XE_ASSEMBLER_ASSEMBLER_H__



#include <iostream>
#include <iomanip>
#include <sstream>

/**
 * utility class for sic assmebler.
 */
class sic_assembler {
public:
    static const int INSTRUCTION_LENGTH = 3;
    static const int LOCATION_LENGTH = 4; // location counter hex degits length.
    static int location_counter;
    static int location_counter_old;
    static int starting_address;
    static int program_length;
    static std::string program_name;
    static const std::string directives[];
    static const int TAB_WIDTH = 8;

    static int hex_to_int(std::string hex);
    static std::string decimal_to_hex(int decimal, int width = -1);
    static std::string to_lower(std::string str);
    static std::string to_upper(std::string str);
    static std::string trim(std::string str);
    static bool is_directive(std::string);
    static std::string remove_tabs(std::string str);
};

#endif // SIC_XE_ASSEMBLER_ASSEMBLER_H__
