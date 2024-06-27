/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:24:19 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/15 23:39:09 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, double>	_priceDb;
	std::string						_filename;
	bool							isValidDate(std::string date);
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	double	getPrice(std::string date);
	void	setPrice(std::string date, double price);
	void	setFilename(std::string filename);
	void	parseFile();
	void	calculatePrice(std::string filename);
};

#endif