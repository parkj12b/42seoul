/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:13:45 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/24 08:06:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "myDefines.hpp"
#include "File.hpp"

int	check_arg_valid(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return (IVNARG);
	}
	
	if (std::strlen(argv[1]) == 0 || std::strlen(argv[2]) == 0
		|| std::strlen(argv[3]) == 0)
	{
		std::cerr << "Invalid argument length" << std::endl;
		return (INVARGL);
	}
	return (SUCCESS);
}

int	readFile(File &file)
{
	std::ifstream in(file.getFileName().data());
	if (!in.is_open())
	{
		std::cerr << "error opening file" << std::endl;
		return (INVFIL);
	}
	
	in.seekg(0, std::ios::end);
	file.setFileSize(in.tellg());
	file.getContent().resize(file.getFileSize());
	in.seekg(0, std::ios::beg);
	in.read(&(file.getContent())[0], file.getFileSize());
	return (SUCCESS);
}

int	writeFile(File &file)
{
	std::ofstream out((file.getFileName() + ".replace").data());
	if (!out.is_open())
	{
		std::cerr << "error opening file" << std::endl;
		return (INVFIL);
	}

	std::string	content = file.getContent();
	std::string	find = file.getSearch();
	std::string	replace = file.getReplace();
	
	size_t nextOccurence = content.find(find, 0);
	for (size_t i = 0; i < file.getFileSize(); i++)
	{
		if (i == nextOccurence && i != std::string::npos)
		{
			out << replace;
			i += find.length() - 1;
			nextOccurence = content.find(find, i + 1);
		}
		else
			out << content[i];
	}
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	int	status = check_arg_valid(argc, argv);
	if (status != SUCCESS)
		return (status);

	File file(argv[1], argv[2], argv[3]);
	status = readFile(file);
	if (status != SUCCESS)
		return (status);
	status = writeFile(file);
	if (status != SUCCESS)
		return (status);
}