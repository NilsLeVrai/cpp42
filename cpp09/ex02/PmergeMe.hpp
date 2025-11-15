#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cmath>

class PmergeMe {

	private:

		std::vector<int> _vectorData;
		std::list<int>   _listData;

		double _elapsedVector;
		double _elapsedList;

		std::vector<long> _jacobstahlVector;
		std::list<long> _jacobstahlList;

		void jacobstahlList();
		void jacobstahlVector();

		std::vector<int> mergeVector(const std::vector<int>& vec);
		std::list<int> mergeList(const std::list<int>& lst);
		std::vector<size_t> insertVector(size_t pendSize);
		std::vector<size_t> insertList(size_t pendSize);

	public:

		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		double getVectorTime() const;
		double getListTime() const;

		void runFordJohnsonVector(std::vector<int>& data);
		void runFordJohnsonList(std::list<int>& data);

		int calculateLeastOperations(int size);
};
