/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:00:49 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/01 15:33:56 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <string>
# include "Bureaucrat.hpp"

class AForm {
private:
	const std::string	_name;
	bool				_isSigned;
	unsigned int		_requiredGradeToSign;
	unsigned int		_requiredGradeToExecute;
	AForm();
public:
	AForm(std::string name, unsigned int requiredGradeToSign,
		unsigned int requiredGradeToExecute);
	virtual	~AForm();
	// AForm(const AForm &aForm);
	std::string		getName() const;
	bool			isSigned() const;
	unsigned int	getRequiredGradeToSign() const;
	unsigned int	getRequiredGradeToExecute() const;
	void			beSigned(Bureaucrat &bureaucrat);
	virtual void	execute(Bureaucrat const &execurtor) const = 0;
	void			checkExecutePermission(Bureaucrat const &executor) const;
	void			checkFormSigned() const;
	class	GradeTooHighException : public std::exception {
	public:
		const char	*what() const throw();	
	};
	class	GradeTooLowException : public std::exception {
		const char	*what() const throw();	
	};
	class	FormNotSignedException : public std::exception {
		const char	*what() const throw();	
	};
};

std::ostream &operator<< (std::ostream &os, AForm &aForm);

#endif