#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _listData(other._listData) {

	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {

	if (this != &other) {
		_vectorData = other._vectorData;
		_listData = other._listData;
	}
	return *this;
}

void PmergeMe::insertData(char** argv) {

	for (int i = 1; argv[i]; i++) {
		int num = std::atoi(argv[i]);
		_vectorData.push_back(num);
		_listData.push_back(num);
	}
}

void PmergeMe::printVector() const {

	for (size_t i = 0; i < _vectorData.size(); i++) {
		std::cout << _vectorData[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printList() const {

	for (std::list<int>::const_iterator it = _listData.begin(); it != _listData.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int PmergeMe::calculateLeastOperations(int size) {

	int sum = 0;
	double value;
	for (int i = 1; i <= size; ++i) {
		value = (3.0 / 4.0) * i;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
}