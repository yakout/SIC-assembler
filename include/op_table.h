//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_OPTABLE_H
#define SIC_XE_ASSEMBLER_OPTABLE_H

#include <unordered_map>
#include "instruction.h"

class op_table {
private:
    std::unordered_map<std::string, std::string> table;
    op_table();
    void init_table();
    static op_table *instance;
public:
    // singleton
    static op_table *get_instance();

//    static op_table& getInstance()
//    {
//        static op_table instance; // Guaranteed to be destroyed.
//         Instantiated on first use.
//        return instance;
//    }

    std::string get(std::string);
    bool lookup(std::string);
};
#endif //SIC_XE_ASSEMBLER_OPTABLE_H
