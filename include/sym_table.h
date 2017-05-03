//
// Created by Ahmed Yakout on 4/24/17.
//

#ifndef SIC_XE_ASSEMBLER_SYM_TABLE_H
#define SIC_XE_ASSEMBLER_SYM_TABLE_H

#include "unordered_map"
#include "iostream"

class sym_table {
private:
    std::unordered_map<std::string, std::string> table;
    sym_table();
public:
    ~sym_table();

    // singleton
    static sym_table* get_instance() {
        static sym_table *instance = new sym_table();
        return instance;
    }

    // check if the symbol table contains some label
    bool lookup(std::string);
    void insert(std::string, int i);
    std::string get(std::string);
};

#endif //SIC_XE_ASSEMBLER_SYM_TABLE_H
