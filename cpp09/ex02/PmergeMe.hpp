#pragma once

#include <iostream>
#include <vector>
#include <list>

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