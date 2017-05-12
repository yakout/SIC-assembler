//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_OPTABLE_H__
#define SIC_XE_ASSEMBLER_OPTABLE_H__

#include <unordered_map>
#include <instruction.h>

class op_table {
private:
    std::unordered_map<std::string, std::string> table;
    op_table();
    void init_table();
public:
    // singleton
    static op_table& get_instance();

    op_table(op_table const&) = delete;
    void operator=(op_table const&) = delete;

    std::string get(std::string);
    bool lookup(std::string);
};
#endif // SIC_XE_ASSEMBLER_OPTABLE_H__
