/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:24:32 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/31 23:27:54 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERY_CREATION_FORM_HPP__
# define __SHRUBBERY_CREATION_FORM_HPP__

# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	ShrubberyCreationForm();
	std::string	_target;
public:
	~ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
	ShrubberyCreationForm	operator= (const ShrubberyCreationForm &rhs);
	void					execute(Bureaucrat const &executor) const;
};

#endif