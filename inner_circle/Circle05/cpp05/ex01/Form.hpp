/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:00:49 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/31 23:18:55 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <string>
# include "Bureaucrat.hpp"

class Form {
private:
	const std::string	_name;
	bool				_isSigned;
	unsigned int		_requiredGradeToSign;
	unsigned int		_requiredGradeToExecute;
	Form();
public:
	Form(std::string name, unsigned int requiredGradeToSign,
		unsigned int requiredGradeToExecute);
	~Form();
	Form(const Form &form);
	Form			operator= (const Form &form);
	std::string		getName() const;
	bool			isSigned() const;
	unsigned int	getRequiredGradeToSign() const;
	unsigned int	getRequiredGradeToExecute() const;
	void			beSigned(Bureaucrat &bureaucrat);
	class	GradeTooHighException : public std::exception {
	public:
		const char	*what() const throw();	
	};
	class	GradeTooLowException : public std::exception {
		const char	*what() const throw();	
	};
};

std::ostream &operator<< (std::ostream &os, Form &form);

#endif