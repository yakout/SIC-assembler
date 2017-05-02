//
// Created by Ahmed Yakout on 5/2/17.
//

#ifndef SIC_ASSEMBLER_LIT_TABLE_H
#define SIC_ASSEMBLER_LIT_TABLE_H

#include <unordered_map>
#include <string>

class lit_table {
private:
    std::unordered_map<std::string, std::string> table;
    lit_table();
    static lit_table* instance;
public:
    ~lit_table();
    static lit_table* get_instance();
    void insert(std::string literal, std::string address);
    bool lookup(std::string);
    std::string get(std::string literal);
};

#endif //SIC_ASSEMBLER_LIT_TABLE_H
