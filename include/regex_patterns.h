//
// Created by Marwan Tammam on 5/1/17.
//

#ifndef SIC_XE_ASSEMBLER_REGEX_PATTERNS_H
#define SIC_XE_ASSEMBLER_REGEX_PATTERNS_H

#define INSTRUCTION_WITH_COMMENT "(?:^)(.{8})\\s(.{6})\\s\\s(.{18})(.*)(?:$)"
#define INSTRUCTION_WITHOUT_COMMENT "(?:^)(.{8})\\s(.{6})\\s\\s(.{1,18})(?:$)"
#define INSTRUCTION_WITHOUT_OPERAND_WITHOUT_COMMENT "(?:^)(.{8})\\s(.{1,6})(?:$)"
#define INSTRUCTION_WITHOUT_OPERAND_WITH_COMMENT "(?:^)(.{8})\\s(.{6})(?:\\s{20})(.*)(?:$)"
#define LABEL_PATTERN "[a-z]\\w*\\s*"
#define LABEL_INDEXED_PATTERN "[a-z]\\w*[,][x]\\s*"
#define EMPTY_STRING_PATTERN "\\s*"
#define DECIMAL_PATTERN "\\d+\\s*"
#define HEXA_PATTERN "[0][x][0-9a-f]+\\s*"
#define REGISTER_PATTERN "[astblx]\\s*"
#define TWO_REGISTERS_PATTERN "[astblx][,][astblx]\\s*"
#define EXPRESSION_PATTERN "\\d([+-]\\d)+\\s*"
#define WORD_LITERAL_PATTERN "[=][c]['][0-9a-z]+[']\\s*"
#define HEXA_LITERAL_PATTERN "[=][x]['][0-9a-f]+[']\\s*"

#endif //SIC_XE_ASSEMBLER_REGEX_PATTERNS_H
