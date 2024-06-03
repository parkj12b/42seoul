/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:45:50 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/31 23:52:21 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIAL_PARDON_FORM__
# define __PRESIDENTIAL_PARDON_FORM__

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(
		const PresidentialPardonForm &PresidentialPardonForm);
	PresidentialPardonForm	operator=(const PresidentialPardonForm &rhs);
	void					execute(Bureaucrat const &executor) const;
};

#endif