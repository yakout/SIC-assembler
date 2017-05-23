//
// Created by Ahmed Yakout on 4/24/17.
//

#ifndef SIC_ASSEMBLER_SYM_TABLE_H__
#define SIC_ASSEMBLER_SYM_TABLE_H__

#include <unordered_map>
#include <fstream>

class sym_table {
private:
    std::unordered_map<std::string, int> table;
    sym_table();
public:
    // singleton
    static sym_table& get_instance();

    sym_table(sym_table const&) = delete;
    void operator=(sym_table const&) = delete;

    bool lookup(std::string);
    void insert(std::string, int i);
    int get(std::string);

    void write_table(std::ofstream&);
};

#endif // SIC_ASSEMBLER_SYM_TABLE_H__
