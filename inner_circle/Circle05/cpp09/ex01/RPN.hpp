/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:46:23 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/16 15:19:00 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
# define __RPN_HPP__

#include <string>
#include <stack>

class RPN {
private:
	std::stack<double> _operands;
public:
	RPN();
	RPN(RPN const &rhs);
	~RPN();
	RPN &operator=(RPN const &rhs);

	void	pushOperand(double operand);
	void	pushOperator(char oper);
	double	getResult() const;
	void	calculateExpression(std::string &expression);
};

#endif