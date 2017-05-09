//
// Created by Ahmed Yakout on 4/23/17.
//

#include <tables/op_table.h>

op_table::op_table() {
    init_table();
}

op_table& op_table::get_instance() {
    static op_table instance;
    return instance;
}

std::string op_table::get(std::string key) {
    return table[key];
}

bool op_table::lookup(std::string label) {
    return table.find(label) != table.end();
}

void op_table::init_table() {
//    table.insert({"add", 24});
//    table.insert({"and", 64});
//    table.insert({"comp", 40});
//    table.insert({"div", 36});
//    table.insert({"j", 60});
//    table.insert({"jgt", 48});
//    table.insert({"jlt", 56});
//    table.insert({"jsub", 72});
//    table.insert({"lda", 0});
//    table.insert({"ldch", 80});
//    table.insert({"ldx", 4});
//    table.insert({"mul", 32});
//    table.insert({"or", 68});
//    table.insert({"rd", 216});
//    table.insert({"rsub", 76});
//    table.insert({"sta", 12});
//    table.insert({"stch", 84});
//    table.insert({"stl", 20});
//    table.insert({"stx", 16});
//    table.insert({"sub", 28});
//    table.insert({"td", 224});
//    table.insert({"tix", 44});
//    table.insert({"wd", 220});

                                 // operand type
    table.insert({"add", "18"}); // m
    table.insert({"and", "40"}); // m
    table.insert({"comp", "28"}); // m
    table.insert({"div", "24"}); // m
    table.insert({"j", "3C"}); // m
    table.insert({"jeq", "30"}); // m
    table.insert({"jgt", "34"}); // m
    table.insert({"jlt", "38"}); // m
    table.insert({"jsub", "48"}); // m
    table.insert({"lda", "00"}); // m
    table.insert({"ldl", "08"}); // m
    table.insert({"ldch", "50"}); // m
    table.insert({"ldx", "04"}); // m
    table.insert({"mul", "20"}); // m
    table.insert({"or", "44"}); // m
    table.insert({"rd", "D8"}); // m
    table.insert({"rsub", "4C"}); // nothing
    table.insert({"sta", "0C"}); // m
    table.insert({"stch", "54"}); // m
    table.insert({"stl", "14"}); // m
    table.insert({"stx", "10"}); // m
    table.insert({"sub", "1C"}); // m
    table.insert({"td", "E0"}); // m
    table.insert({"tix", "2C"}); // m
    table.insert({"wd", "DC"}); // m
}
