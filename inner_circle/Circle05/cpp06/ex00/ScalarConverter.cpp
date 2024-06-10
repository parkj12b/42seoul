/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:40:39 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/04 17:38:49 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <cmath>
#include <iomanip>
#include "ScalarConverter.hpp"

int	checkType(std::string str)
{
	if (str.size() == 0)
		return 0;
	
	int	flag = 0;

	flag |= isChar(str);
	flag |= isInt(str);
	
	flag |= isFloat(str);
	flag |= isDouble(str);
	return flag;
}

int	isChar(std::string str)
{
	if (str.size() == 1 && !std::isdigit(str[0]))
		return SCALAR_CHAR;
	return 0;
}

int	isInt(std::string str)
{
	std::istringstream	iss(str);
	int					i_str;
	
	if(iss >> i_str && iss.eof())
		return SCALAR_INT;
	return 0;
}
int	isFloat(std::string str)
{
	char		*end_ptr;
	if (str.find('.') == std::string::npos)
		return 0;
	if ((strtof(str.c_str(), &end_ptr) == std::numeric_limits<float>::infinity()
		|| strtof(str.c_str(), &end_ptr)
			== std::numeric_limits<float>::infinity() * -1.0f)
			&& *end_ptr == 'f' && *(end_ptr + 1) == '\0')
		return SCALAR_FLOAT;
	if (str.find('f') != str.size() - 1)
		return 0;
	str = str.substr(0, str.size() - 1);
	
	const char	*c_str = str.c_str();
	strtof(c_str, &end_ptr);
	
	if (*end_ptr != '\0')
	{
		return 0;
	}
	while (*end_ptr != '\0')
	{
        if (!isspace(*end_ptr))
            return 0;
        ++end_ptr;
    }
	return SCALAR_FLOAT;
}

int	isDouble(std::string str)
{
	const char	*c_str = str.c_str();
	char		*end_ptr;
	
	if (str.find('.') == std::string::npos)
		return 0;
	strtod(c_str, &end_ptr);
	if (*end_ptr != '\0')
		return 0;
	while (*end_ptr != '\0')
	{
        if (!isspace(*end_ptr))
            return false;
        ++end_ptr;
    }
	return SCALAR_DOUBLE;
}

void	ScalarConverter::convert(std::string str)
{
	int flag = checkType(str);
	
	std::cout << std::fixed;
	
	if (flag & SCALAR_FLOAT)
		flag &= ~SCALAR_DOUBLE;
	if (flag & SCALAR_INT)
		flag &= ~SCALAR_DOUBLE;
	
	std::istringstream	iss(str);
	char				c;
	int					i;
	float				f;
	double				d = strtod(str.c_str(), NULL);
	bool				impossible = 0;

	switch (flag)
	{
	case SCALAR_CHAR:
		c = str[0];
		displayChar(static_cast<char>(c), 0);
		displayInt(static_cast<int>(c), 0);
		std::cout << std::setprecision(1);
		displayFloat(static_cast<float>(c), 0);
		displayDouble(static_cast<double>(c), 0);
		break;
	case SCALAR_INT:
		iss >> i;
		displayChar(static_cast<char>(i), 0);
		displayInt(static_cast<int>(i), 0);
		std::cout << std::setprecision(1);
		displayFloat(static_cast<float>(i), 0);
		displayDouble(static_cast<double>(i), 0);
		break;
	case SCALAR_FLOAT:
		f = strtof(str.c_str(), NULL);
		if (std::isnan(f) || d > std::numeric_limits<int>::max()
			|| d < std::numeric_limits<int>::min())
			impossible = 1;
		displayChar(static_cast<char>(f), impossible);
		displayInt(static_cast<int>(f), impossible);
		std::cout << std::setprecision(std::max(findDecimalCount(str) - 1, 1));
		displayFloat(static_cast<float>(f), 0);
		displayDouble(static_cast<double>(f), 0);
		break;
	case SCALAR_DOUBLE:
		if (std::isnan(d) || d > std::numeric_limits<int>::max()
			|| d < std::numeric_limits<int>::min())
			impossible = 1;
		displayChar(static_cast<char>(d), impossible);
		displayInt(static_cast<int>(d), impossible);
		std::cout << std::setprecision(std::max(findDecimalCount(str), 1));
		displayFloat(static_cast<float>(d), 0);
		displayDouble(static_cast<double>(d), 0);
		break;
	default:
		displayChar(0, 1);
		displayInt(0, 1);
		displayFloat(0, 1);
		displayDouble(0, 1);
		break;
	}
}

void	displayChar(char c, bool impossible)
{
	if (impossible)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: \'" << c << "\'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
}

void	displayInt(int i, bool impossible)
{
	if (impossible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	displayFloat(float f, bool impossible)
{
	std::cout << "float: ";
	if (impossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

void	displayDouble(double d, bool impossible)
{
	std::cout << "double: ";
	if (impossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << d << std::endl;
}

int findDecimalCount(std::string d)
{
	if (d.find('.') == std::string::npos)
		return (0);
	return (d.size() - d.find('.') - 1);
}