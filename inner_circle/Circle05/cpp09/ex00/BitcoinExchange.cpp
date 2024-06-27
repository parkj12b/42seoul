/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:28:23 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/20 19:03:28 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_priceDb = other._priceDb;
	}
	return *this;
}

double	BitcoinExchange::getPrice(std::string date) {
	std::map<std::string, double>::iterator iter = _priceDb.upper_bound(date);
	if (iter == _priceDb.begin())
		throw std::runtime_error("no price available for this date");
	if (date != iter->first)
		--iter;
	return iter->second;
}

void	BitcoinExchange::setPrice(std::string date, double price) {
	_priceDb[date] = price;
}

void	BitcoinExchange::setFilename(std::string filename) {
	_filename = filename;
}

bool	BitcoinExchange::isValidDate(std::string date)
{
	if (date.size() != 10)
		return false;
	
	if (date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
	std::stringstream ss(date.substr(0, 4));
	ss >> year;
	ss.clear();
	ss.str(date.substr(5, 2));
	ss >> month;
	ss.clear();
	ss.str(date.substr(8, 2));
	ss >> day;
	
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false ;
	
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false ;

	if (month == 2)
	{
		bool leapYear = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
		if (leapYear && day > 29)
			return false ;
		else if (!leapYear && day > 28)
			return false ;
	}

	return true ;
}

void	BitcoinExchange::parseFile() {
	std::string line;
	std::ifstream in(_filename.data());

	if (!in.is_open()) {
		std::cerr << "error opening file" << std::endl;
		throw std::runtime_error("parse file does not exist");
	}

	std::getline(in, line);
	char *end;
	while (std::getline(in, line)) {
		size_t pos = line.find(',');
		std::string date = line.substr(0, pos);

		if (isValidDate(date) == false)
			continue ;
		float price = std::strtof(line.substr(pos + 1).c_str(), &end);
		if (*end != '\0')
			continue ;
		if (price < 0)
			continue ;
		_priceDb[date] = price;
	}
}

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");

    if (start == std::string::npos)
        return "";

    return str.substr(start, end - start + 1);
}

void	BitcoinExchange::calculatePrice(std::string filename) {
	std::ifstream in(filename.data());
	std::string line;
	char		*end;

	if (!in.is_open()) {
		throw std::runtime_error("error opening file");
	}
	std::getline(in, line);
	while (std::getline(in, line)) {
		size_t pos = line.find('|');
		std::string date = line.substr(0, pos);
		date = trim(date);
		// std::cout << "pos: " << pos << std::endl;
		if (isValidDate(date) == false || pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << date << std::endl; 
			continue ;
		}
		float numCoin = std::strtof(trim(line.substr(pos + 1)).c_str(), &end);
		if (*end != '\0')
		{
			std::cout << "Error: invalid coin number" << std::endl;
			continue;
		}
		if (numCoin < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		else if (numCoin == 0 || numCoin >= 1000)
		{
			std::cout << "Error: invalid number" << std::endl;
			continue ;
		}
		try {
			double d = getPrice(date);
			std::cout << date << " => ";
			std::cout << numCoin << " = " << d * numCoin << std::endl;
		} catch (std::exception &e) {
			std::cout << "Error: bad input => " << date << std::endl;
		}
	}
}
