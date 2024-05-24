/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:22:06 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/23 16:23:00 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "File.hpp"

std::string	&File::getContent(void)
{
	return _content;
}

std::string File::getFileName(void)
{
	return _fileName;
}

std::string File::getSearch(void)
{
	return _search;
}

std::string File::getReplace(void)
{
	return _replace;
}

File::File(std::string fileName, std::string search,
		std::string replace)
	:_fileName(fileName), _search(search), _replace(replace)
{
}
void	File::setContent(std::string content)
{
	_content = content;
}

void	File::setFileSize(size_t size)
{
	_fileSize = size;
}

size_t	File::getFileSize(void)
{
	return _fileSize;
}