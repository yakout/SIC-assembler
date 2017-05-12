//
// Created by Ahmed Yakout on 5/2/17.
//

#ifndef SIC_ASSEMBLER_LIT_TABLE_H__
#define SIC_ASSEMBLER_LIT_TABLE_H__

#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>

class lit_table {
private:
    std::unordered_map<std::string, int> table;
    std::vector<std::string> unassigned_literals;
    std::ofstream* listing_file;
    std::ofstream* intermediate_file;

    lit_table();
public:
    // singleton
    static lit_table& get_instance();

    lit_table(lit_table const&) = delete;
    void operator=(lit_table const&) = delete;

    void insert(std::string literal, int address);
    void insert(std::string literal);
    bool lookup(std::string);
    int get(std::string literal);
    std::vector<std::string> get_unassigned_literals();

    void set_ofstreams(std::ofstream*, std::ofstream*);
    void append_unassgined_literals();
    void write_table(std::ofstream&);
};

#endif // SIC_ASSEMBLER_LIT_TABLE_H__
