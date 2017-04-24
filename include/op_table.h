//
// Created by Ahmed Yakout on 4/23/17.
//

#ifndef SIC_XE_ASSEMBLER_OPTABLE_H
#define SIC_XE_ASSEMBLER_OPTABLE_H

#include <unordered_map>
#include "instruction.h"
using namespace std;

namespace assembler {
    class op_table {
    private:
        unordered_map<string, string> optab;
        op_table(){};
        static op_table* instance;
    public:
        // singleton
        static op_table* getInstance();
        string get(string);
    };
}


#endif //SIC_XE_ASSEMBLER_OPTABLE_H
