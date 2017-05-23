//
// Created by Ahmed Yakout on 5/14/17.
//

#ifndef SIC_ASSEMBLER_EXPRESSION_EVALUATOR_H__
#define SIC_ASSEMBLER_EXPRESSION_EVALUATOR_H__

#include <string>

class expression_evaluator {
private:
	std::string expression;
public:
	expression_evaluator(std::string);
	~expression_evaluator();
	std::string evaluate();
};


#endif // SIC_ASSEMBLER_EXPRESSION_EVALUATOR_H__