/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:00:45 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/04 16:51:26 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALAR_CONVERTER_HPP__
# define __SCALAR_CONVERTER_HPP__

# include <string>

enum scalar_type {
	SCALAR_CHAR = 1,
	SCALAR_INT = 2,
	SCALAR_FLOAT = 4,
	SCALAR_DOUBLE = 8
};

class ScalarConverter {
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &scalarConverter);
	ScalarConverter	operator= (const ScalarConverter &rhs);
public:
	static void	convert(std::string str);
	
};

int	checkType(std::string str);
int	isChar(std::string str);
int	isInt(std::string str);
int	isFloat(std::string str);
int	isDouble(std::string str);
void	displayChar(char c, bool impossible);
void	displayInt(int i, bool impossible);
void	displayFloat(float f, bool impossible);
void	displayDouble(double d, bool impossible);
int		findDecimalCount(std::string d);

#endif