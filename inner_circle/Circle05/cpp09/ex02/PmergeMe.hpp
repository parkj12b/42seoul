/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:24:25 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/27 23:13:17 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

#include <string>
#include <deque>
#include <vector>
#include <iostream>
#include <sstream>

#define ArrayIndex(x) (x - 1)

class PmergeMe {
private:
	size_t								timeDeque;
	size_t								timeVector;
	std::vector<int>					jacobsthal;
	int									findParentIdx(int idx);
	std::deque< std::pair<int,int> >
		recursiveSortDeque(std::deque< std::pair<int, int> > &d);
	std::vector< std::pair<int, int> >
		recursiveSortVector(std::vector< std::pair<int, int> > &v);
	
	template <typename T>
	void	parseInput(char **argv, T &v);
	
	template <typename T>
	int	binarySearch(T &insertV, int val, int jacobsthal);
	
	template <typename T>
	void	printContainer(T &v)
	{
		for (typename T::iterator it = v.begin(); it != v.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	
	template <>
	void	printContainer(std::vector< std::pair<int, int> > &v)
	{
		for (std::vector< std::pair<int, int> >::iterator it = v.begin();
			it != v.end(); ++it)
			std::cout << it->first << " ";
		std::cout << std::endl;
	}
	
	template <>
	void	printContainer(std::deque< std::pair<int, int> > &v)
	{
		for (std::deque< std::pair<int, int> >::iterator it = v.begin();
			it != v.end(); ++it)
			std::cout << it->first << " ";
		std::cout << std::endl;
	}

	template<typename T>
	void	testing(T &pair, T &result)
	{
		std::sort(pair.begin(), pair.end());
		std::cout << "testing: " << std::endl;
		printContainer(pair);
		if (pair.size() != result.size())
		{
			std::cout << "size diff KO" << std::endl;
			return ;
		}
		for (unsigned int i = 0; i < pair.size(); i++)
		{
			if (pair[i].first != result[i].first)
			{
				std::cout << "value diff KO" << std::endl;
				return ;
			}
		}
	}

public:
	PmergeMe();
	~PmergeMe();
	// PmergeMe(const PmergeMe &copy);
	// PmergeMe	&operator=(const PmergeMe &copy);
	size_t		getTimeDeque() const;
	size_t		getTimeVector() const;
	void		sortDeque(char **argv);
	void		sortVector(char **argv);
	void		calculateJacobsthal(int n);
	std::pair<int, int> findChildEle(std::deque< std::pair<int, int> >, int idx);
};

template <typename T>
void	PmergeMe::parseInput(char **argv, T &v)
{
	for (int i = 1; argv[i]; i++)
	{
		std::stringstream	ss(argv[i]);
		int					val;

		ss >> val;
		if (ss.fail() || !ss.eof() || val < 0)
			throw std::invalid_argument("invalid argument");
		v.push_back(std::make_pair<int, int>(val, -1));
	}
}
template <typename T>
int	PmergeMe::binarySearch(T &insertV, int val, int jacobsthal)
{
	int low = 0;
	int high = jacobsthal;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (insertV[mid].first == val)
			return mid;
		else if (insertV[mid].first < val)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
}

#endif