/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:03:58 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/01 15:34:56 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() {}

AForm::AForm(std::string name, unsigned int requiredGradeToSign,
             unsigned int requiredGradeToExecute)
    : _name(name),
      _isSigned(false),
      _requiredGradeToSign(requiredGradeToSign),
      _requiredGradeToExecute(requiredGradeToExecute) {
  if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
    throw GradeTooHighException();
  else if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
    throw GradeTooLowException();
}

AForm::~AForm() {}

// AForm::AForm(const AForm &aForm) { *this = aForm; }

std::string AForm::getName() const { return _name; }

bool AForm::isSigned() const { return _isSigned; }

unsigned int AForm::getRequiredGradeToSign() const { return _requiredGradeToSign; }

unsigned int AForm::getRequiredGradeToExecute() const {
  return _requiredGradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _requiredGradeToSign)
    throw GradeTooLowException();
  _isSigned = true;
}
std::ostream &operator<<(std::ostream &os, AForm &aForm) {
  os << "Name: [" << aForm.getName() << "]\n"
     << "aForm Sign State: [" << std::boolalpha << aForm.isSigned() << "]\n"
     << "Required Grade To Sign: [" << aForm.getRequiredGradeToSign() << "]\n"
     << "Required Grade To Execute [" << aForm.getRequiredGradeToExecute()
     << "]" << std::endl;
  return os;
}

void  AForm::checkExecutePermission(Bureaucrat const &executor) const
{
  if (executor.getGrade() > _requiredGradeToExecute)
    throw GradeTooLowException();
}

void  AForm::checkFormSigned() const
{
  if (_isSigned == false)
    throw FormNotSignedException();
}

const char  *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char  *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char  *AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed";
}