#pragma once

#include <iostream>
#include <vector>
#include <list>

class PmergeMe {

	private:

		std::vector<int> _vectorData;
		std::list<int>   _listData;

	public:

		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		void insertData(char** argv);
		void mergeInsertSortVector(int left, int right);
		void mergeInsertSortList(std::list<int>::iterator left, std::list<int>::iterator right);
		void printVector() const;
		void printList() const;
		int calculateLeastOperations(int size);

};