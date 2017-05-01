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
#define EMPTY_STRING_PATTERN "\\s*"


#endif //SIC_XE_ASSEMBLER_REGEX_PATTERNS_H
