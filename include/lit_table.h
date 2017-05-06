//
// Created by Ahmed Yakout on 5/2/17.
//

#ifndef SIC_ASSEMBLER_LIT_TABLE_H
#define SIC_ASSEMBLER_LIT_TABLE_H

#include <unordered_map>
#include <string>
#include <vector>

class lit_table {
private:
    std::unordered_map<std::string, std::string> table;
    std::vector<std::string> unassigned_literals;
    lit_table();
    
public:
    // singleton
    static lit_table& get_instance();

    lit_table(lit_table const&) = delete;
    void lit_table=(lit_table const&) = delete;

    void insert(std::string literal, std::string address);
    void insert(std::string literal);
    bool lookup(std::string);
    std::string get(std::string literal);
    std::vector<std::string> get_unassigned_literals();
};

#endif //SIC_ASSEMBLER_LIT_TABLE_H
