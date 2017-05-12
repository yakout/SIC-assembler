//
// Created by Ahmed Yakout on 5/8/17.
//

#ifndef SIC_ASSEMBLER_ASSEMBLER_ERROR_H__
#define SIC_ASSEMBLER_ASSEMBLER_ERROR_H__

#include <exception>
#include <string>

class assembler_error: public std::exception {
public:
	assembler_error();
	virtual const char* what() const throw() = 0;
};

#endif // SIC_ASSEMBLER_ASSEMBLER_ERROR_H__