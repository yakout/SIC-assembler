//
// Created by Marwan Tammam on 5/1/17.
//

#ifndef SIC_XE_ASSEMBLER_REGEX_PATTERNS_H
#define SIC_XE_ASSEMBLER_REGEX_PATTERNS_H

#define LC_INSTRUCTION_WITH_COMMENT "(?:^)([0-9a-f]{4})(?:\\s{5})\\s(.{8})\\s(.{6})\\s\\s(.{18})(.*)(?:$)"
#define LC_INSTRUCTION_WITHOUT_COMMENT "(?:^)([0-9a-f]{4})(?:\\s{5})\\s(.{8})\\s(.{6})\\s\\s(.{1,18})(?:$)"
#define LC_INSTRUCTION_WITHOUT_OPERAND_WITHOUT_COMMENT "(?:^)([0-9a-f]{4})(?:\\s{5})\\s(.{8})\\s(.{1,6})(?:$)" // todo: remove \\s and put just space
#define LC_INSTRUCTION_WITHOUT_OPERAND_WITH_COMMENT "(?:^)([0-9a-f]{4})(?:\\s{5})\\s(.{8})\\s(.{6})(?:\\s{20})(.*)(?:$)"
#define INSTRUCTION_WITH_COMMENT "(?:^)(.{8})\\s(.{6})\\s\\s(.{18})(.*)(?:$)"
#define INSTRUCTION_WITHOUT_COMMENT "(?:^)(.{8})\\s(.{6})\\s\\s(.{1,18})(?:$)"
#define INSTRUCTION_WITHOUT_OPERAND_WITHOUT_COMMENT "(?:^)(.{8})\\s(.{1,6})(?:$)" // todo: remove \\s and put just space
#define INSTRUCTION_WITHOUT_OPERAND_WITH_COMMENT "(?:^)(.{8})\\s(.{6})(?:\\s{20})(.*)(?:$)"
#define LABEL_PATTERN "[a-z]\\w*\\s*"
#define LABEL_INDEXED_PATTERN "[a-z]\\w*[,][x]\\s*"
#define EMPTY_STRING_PATTERN "\\s*"
#define DECIMAL_PATTERN "\\d+"
#define HEXA_PATTERN "[0][x][0-9a-f]+"
#define REGISTER_PATTERN "[astblx]"
#define TWO_REGISTERS_PATTERN "[astblx][,][astblx]"
#define EXPRESSION_PATTERN "\\d+([+-]\\d+)+"
#define WORD_LITERAL_PATTERN "[=][c]['][0-9a-z]+[']"
#define HEXA_LITERAL_PATTERN "[=][x]['][0-9a-f]+[']"
#define HEXA_STRING_PATTERN "[x]['][0-9a-f]+[']"
#define STRING_PATTERN "[c]['].+[']"
#define DECIMAL_ARRAY_PATTERN "\\d+([,]\\d+)*"

#endif //SIC_XE_ASSEMBLER_REGEX_PATTERNS_H
