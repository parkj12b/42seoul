/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:42:00 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/01 15:42:29 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <string>
# include <iostream>

class	AForm;

class Bureaucrat {
private:
	const std::string	_name;
	unsigned int		_grade;
	Bureaucrat();
public:
	~Bureaucrat();
	Bureaucrat(const std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat			operator= (const Bureaucrat &bureaucrat);
	const std::string	&getName() const;
	unsigned int		getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(AForm &aForm);
	void				executeForm(AForm const &form);
	class	GradeTooHighException : public std::exception {
	public:
		const char	*what() const throw();	
	};
	class	GradeTooLowException : public std::exception {
		const char	*what() const throw();	
	};
};

std::ostream	&operator<< (std::ostream& os, const Bureaucrat& bureaucrat);

#endif