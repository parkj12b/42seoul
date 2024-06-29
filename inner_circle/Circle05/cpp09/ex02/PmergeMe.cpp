/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:18:41 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/27 15:46:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <map>
#include <sstream>
#include <sys/time.h>
#include <unistd.h>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::calculateJacobsthal(int n)
{
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	int max = 1;
	while (max <= n)
	{
		max = jacobsthal[jacobsthal.size() - 1] + 2
			* jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(max);
	}
}

void	PmergeMe::sortDeque(char **argv)
{
	struct timeval	start, end;
	std::deque< std::pair<int, int> >	deque;
	std::deque< std::pair<int, int> >	result;

	parseInput(argv, deque);
	std::cout << "Before: ";
	printContainer(deque);
	gettimeofday(&start, NULL);
	result = recursiveSortDeque(deque);
	gettimeofday(&end, NULL);
	std::cout << "After: ";
	printContainer(result);
	timeDeque = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
	testing(deque, result);
}

void	PmergeMe::sortVector(char **argv)
{
	struct timeval	start, end;
	std::vector< std::pair<int, int> >	vector;
	std::vector< std::pair<int, int> >	result;

	parseInput(argv, vector);
	gettimeofday(&start, NULL);
	result = recursiveSortVector(vector);
	gettimeofday(&end, NULL);
	timeVector = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
	testing(vector, result);
}

std::deque< std::pair<int, int> >	PmergeMe::recursiveSortDeque(std::deque< std::pair<int, int> > &d)
{
	std::deque< std::pair<int, int> >	newDeque;
	std::deque< std::pair<int, int> >	mainDeque;
	std::deque< std::pair<int, int> >	result;
	int									numGroups = d.size() / 2;
	int									numSubChain = numGroups;
	if (d.size() % 2 == 1)
		numSubChain++;

	if (d.size() <= 1)
		return d;

	for (int i = 0; i < numGroups; i++)
	{
		if (d[i * 2].first > d[i * 2 + 1].first)
			newDeque.push_back(std::make_pair(d[i * 2].first, i * 2 + 1));
		else
			newDeque.push_back(std::make_pair(d[i * 2 + 1].first, i * 2));
	}

	result = recursiveSortDeque(newDeque);
	// std::cout << "d: ";
	// printContainer(d);
	// std::cout << "newDeque: ";
	// printContainer(newDeque);
	// std::cout << "result: ";
	// printContainer(result);
	mainDeque = result;
	for (int i = 0, size = result.size(); i < size; i++)
	{
		int parentIdx = findParentIdx(result[i].second);
		result[i].second = d[parentIdx].second;
	}
	int i = 2;
	int j = 0;
	bool end = false;
	while (true)
	{
		int subChainIdx = jacobsthal[i];
		if (subChainIdx >= numSubChain)
		{
			subChainIdx = numSubChain;
			end = true;
		}
		while (subChainIdx > j)
		{
			if (subChainIdx > numGroups)
			{
				std::pair<int, int> childEle = d[d.size() - 1];
				int insertIdx = binarySearch(result, childEle.first,
					std::min(ArrayIndex(jacobsthal[i] + jacobsthal[i - 1]),
						static_cast<int>(ArrayIndex(result.size()))));
				result.insert(result.begin() + insertIdx, childEle);
			}
			else
			{
				int childIdx = mainDeque[ArrayIndex(subChainIdx)].second;
				std::pair<int, int> childEle = d[childIdx];
				int insertIdx = binarySearch(result, childEle.first,
					std::min(ArrayIndex(jacobsthal[i] + jacobsthal[i - 1]),
					static_cast<int>(ArrayIndex(result.size()))));
				result.insert(result.begin() + insertIdx, childEle);
			}
			// printContainer(result);
			subChainIdx--;
		}
		if (end)
			break ;
		j = jacobsthal[i];
		i++;
		
	}
	// std::cout << "before return: ";
	// printContainer(result);
	// std::cout << "====================================" << std::endl;
	return result;
}

std::vector< std::pair<int, int> >	PmergeMe::recursiveSortVector(std::vector< std::pair<int, int> > &d)
{
	std::vector< std::pair<int, int> >	newDeque;
	std::vector< std::pair<int, int> >	mainDeque;
	std::vector< std::pair<int, int> >	result;
	int									numGroups = d.size() / 2;
	int									numSubChain = numGroups;
	if (d.size() % 2 == 1)
		numSubChain++;

	if (d.size() <= 1)
		return d;

	for (int i = 0; i < numGroups; i++)
	{
		if (d[i * 2].first > d[i * 2 + 1].first)
			newDeque.push_back(std::make_pair(d[i * 2].first, i * 2 + 1));
		else
			newDeque.push_back(std::make_pair(d[i * 2 + 1].first, i * 2));
	}

	result = recursiveSortVector(newDeque);
	// std::cout << "d: ";
	// printContainer(d);
	// std::cout << "newDeque: ";
	// printContainer(newDeque);
	// std::cout << "result: ";
	// printContainer(result);
	mainDeque = result;
	for (int i = 0, size = result.size(); i < size; i++)
	{
		int parentIdx = findParentIdx(result[i].second);
		result[i].second = d[parentIdx].second;
	}
	int i = 2;
	int j = 0;
	bool end = false;
	while (true)
	{
		int subChainIdx = jacobsthal[i];
		if (subChainIdx >= numSubChain)
		{
			subChainIdx = numSubChain;
			end = true;
		}
		while (subChainIdx > j)
		{
			if (subChainIdx > numGroups)
			{
				std::pair<int, int> childEle = d[d.size() - 1];
				int insertIdx = binarySearch(result, childEle.first,
					std::min(ArrayIndex(jacobsthal[i] + jacobsthal[i - 1]),
						static_cast<int>(ArrayIndex(result.size()))));
				result.insert(result.begin() + insertIdx, childEle);
			}
			else
			{
				int childIdx = mainDeque[ArrayIndex(subChainIdx)].second;
				std::pair<int, int> childEle = d[childIdx];
				int insertIdx = binarySearch(result, childEle.first,
					std::min(ArrayIndex(jacobsthal[i] + jacobsthal[i - 1]),
					static_cast<int>(ArrayIndex(result.size()))));
				result.insert(result.begin() + insertIdx, childEle);
			}
			// printContainer(result);
			subChainIdx--;
		}
		if (end)
			break ;
		j = jacobsthal[i];
		i++;
		
	}
	// std::cout << "before return: ";
	// printContainer(result);
	// std::cout << "====================================" << std::endl;
	return result;
}



size_t	PmergeMe::getTimeDeque() const
{
	return timeDeque;
}

size_t	PmergeMe::getTimeVector() const
{
	return timeVector;
}

int	PmergeMe::findParentIdx(int idx)
{
	if (idx % 2 == 0)
		return idx + 1;
	else
		return idx - 1;
}
