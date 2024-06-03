/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:03:58 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/31 23:19:10 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
{
}

Form::Form(std::string name, unsigned int requiredGradeToSign,
	unsigned int requiredGradeToExecute)
	:_name(name), _isSigned(false), _requiredGradeToSign(requiredGradeToSign)
		, _requiredGradeToExecute(requiredGradeToExecute)
{
	if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
		throw GradeTooHighException();
	else if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(const Form &form)
{
	*this = form;
}

Form	Form::operator= (const Form &form)
{
	if (this != &form)
	{
		_isSigned = form._isSigned;
		_requiredGradeToSign = form._requiredGradeToSign;
		_requiredGradeToExecute = form._requiredGradeToExecute;
	}
	return *this;
}

std::string	Form::getName() const
{
	return _name;
}

bool	Form::isSigned() const
{
	return _isSigned;
}

unsigned int	Form::getRequiredGradeToSign() const
{
	return _requiredGradeToSign;
}

unsigned int	Form::getRequiredGradeToExecute() const
{
	return _requiredGradeToExecute;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _requiredGradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}
std::ostream	&operator<< (std::ostream &os, Form &form)
{
	os << "Name: [" << form.getName() << "]\n"
		<< "Form Sign State: [" << std::boolalpha << form.isSigned() << "]\n"
		<< "Required Grade To Sign: [" << form.getRequiredGradeToSign() << "]\n"
		<< "Required Grade To Execute [" << form.getRequiredGradeToExecute()
		<< "]" << std::endl;
	return os;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
