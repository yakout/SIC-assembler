//
// Created by Marwan Tammam on 5/1/17.
//

#ifndef SIC_XE_ASSEMBLER_REGEX_PATTERNS_H__
#define SIC_XE_ASSEMBLER_REGEX_PATTERNS_H__

#define LC_INSTRUCTION_WITH_COMMENT "(?:^)([0-9a-f]{4})(?:\\s{3})\\s(.{8})\\s(.{6})\\s\\s(.{18})(.*)(?:$)"
#define LC_INSTRUCTION_WITHOUT_COMMENT "(?:^)([0-9a-f]{4})(?:\\s{3})\\s(.{8})\\s(.{6})\\s\\s(.{1,18})(?:$)"
#define LC_INSTRUCTION_WITHOUT_OPERAND_WITHOUT_COMMENT "(?:^)([0-9a-f]{4})(?:\\s{3})\\s(.{8})\\s(.{1,6})(?:$)" // todo: remove \\s and put just space
#define LC_INSTRUCTION_WITHOUT_OPERAND_WITH_COMMENT "(?:^)([0-9a-f]{4})(?:\\s{3})\\s(.{8})\\s(.{6})(?:\\s{20})(.*)(?:$)"
#define INSTRUCTION_WITH_COMMENT "(?:^)(.{8})\\s(.{6})\\s\\s(.{18})(.*)(?:$)"
#define INSTRUCTION_WITHOUT_COMMENT "(?:^)(.{8})\\s(.{6})\\s\\s(.{1,18})(?:$)"
#define INSTRUCTION_WITHOUT_OPERAND_WITHOUT_COMMENT "(?:^)(.{8})\\s(.{1,6})(?:$)" // todo: remove \\s and put just space
#define INSTRUCTION_WITHOUT_OPERAND_WITH_COMMENT "(?:^)(.{8})\\s(.{6})(?:\\s{20})(.*)(?:$)"
#define LABEL_PATTERN "[a-z]\\w*\\s*"
#define LABEL_INDEXED_PATTERN "[a-z]\\w*[,][x]\\s*"
#define EMPTY_STRING_PATTERN "\\s*"
#define DECIMAL_PATTERN "\\d+"
#define HEXA_PATTERN "[0][x][0-9a-f]+"
// #define REGISTER_PATTERN "[astblx]"
// #define TWO_REGISTERS_PATTERN "[astblx][,][astblx]"
#define EXPRESSION_PATTERN "((\\d+)|([a-z]\\w*))[+-]((\\d+)|([a-z]\\w*))"
#define WORD_LITERAL_PATTERN "[=][0-9]+"
#define HEXA_LITERAL_PATTERN "[=][x]['][0-9a-f]+[']"
#define CHAR_LITERAL_PATTERN "[=][cC]['][0-9a-zA-Z]+[']"
#define HEXA_STRING_PATTERN "[x]['][0-9a-f]+[']"
#define STRING_PATTERN "[c]['].+[']"
#define DECIMAL_ARRAY_PATTERN "\\d+([,]\\d+)*"
#define LITERAL_FORMAT "^[0-9a-f]{4}\\s{4}\\*\\s{8}[=]([0-9]+|[c]['][a-zA-Z]+[']|[x]['][0-9a-fA-F]+['])$"

#endif // SIC_XE_ASSEMBLER_REGEX_PATTERNS_H__
