/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:20:39 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/01 14:58:21 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMY_REQUEST_FORM_HPP__
# define __ROBOTOMY_REQUEST_FORM_HPP__

# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	RobotomyRequestForm();
	std::string	_target;
public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm);
	RobotomyRequestForm	operator=(const RobotomyRequestForm &rhs);
	void				execute(Bureaucrat const &executor) const;
};

#endif