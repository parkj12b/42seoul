/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:53:03 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/01 15:42:52 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::~Bureaucrat()
{	
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
	:_name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat	Bureaucrat::operator= (const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		_grade = rhs._grade;
	}
	return *this;
}

const std::string	&Bureaucrat::getName() const
{
	return _name;
}

unsigned int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream	&operator<< (std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
		<< std::endl;
	return os;
}

void	Bureaucrat::signForm(AForm &aForm)
{
	try {
		aForm.beSigned(*this);
		std::cout << _name << " signed " << aForm.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << _name << " couldn't sign " << aForm.getName()
			<< " because " << e.what() << std::endl;
	}
}

void  Bureaucrat::executeForm(AForm const &form)
{
  try
  {
    form.execute(*this);
	std::cout << _name << " executed " << form.getName() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << "could not execute [" << form.getName() << "] " <<
      e.what() << std::endl;
  }
}
