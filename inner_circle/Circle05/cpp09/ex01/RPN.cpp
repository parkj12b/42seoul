/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:51:32 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/16 15:18:54 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &rhs) {
	*this = rhs;
}

RPN::~RPN() {}

RPN &RPN::operator=(RPN const &rhs) {
	if (this != &rhs) {
		_operands = rhs._operands;
	}
	return *this;
}

void RPN::pushOperand(double operand) {
	_operands.push(operand);
}

void RPN::pushOperator(char oper) {
	double op1;
	double op2;

	if (_operands.size() < 2) {
		throw std::runtime_error("Not enough operands");
	}

	op2 = _operands.top();
	_operands.pop();
	op1 = _operands.top();
	_operands.pop();

	switch (oper) {
		case '+':
			_operands.push(op1 + op2);
			break;
		case '-':
			_operands.push(op1 - op2);
			break;
		case '*':
			_operands.push(op1 * op2);
			break;
		case '/':
			if (op2 == 0) {
				throw std::runtime_error("Division by zero");
			}
			_operands.push(op1 / op2);
			break;
		default:
			throw std::runtime_error("Invalid operator");
	}
}

void RPN::calculateExpression(std::string &expression) {
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token) {
		if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
			pushOperand(std::stod(token));
		} else if (token.size() == 1) {
			pushOperator(token[0]);
		} else {
			throw std::runtime_error("Invalid expression");
		}
	}
	
}

double RPN::getResult() const {
	if (_operands.size() != 1) {
		throw std::runtime_error("Invalid expression");
	}
	return _operands.top();
}