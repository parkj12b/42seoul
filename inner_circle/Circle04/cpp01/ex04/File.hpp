/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:16:57 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/23 16:43:20 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __FILE_HPP__
# define __FILE_HPP__

#include <fstream>

class File {
public:
	File(std::string fileName, std::string search, std::string replace);
	std::string &getContent(void);
	std::string getFileName(void);
	std::string getSearch(void);
	std::string getReplace(void);
	size_t		getFileSize(void);
	void		setContent(std::string content);
	void		setFileSize(size_t size);
private:
	std::string	_content;
	std::string	_fileName;
	std::string	_search;
	std::string	_replace;
	size_t		_fileSize;
};

#endif