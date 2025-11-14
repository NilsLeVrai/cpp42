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

double PmergeMe::getVectorTime() const {
	return _elapsedVector;
}

void PmergeMe::runFordJohnsonVector(std::vector<int>& data) {
	clock_t start = clock();
	int res = 0;
	for (size_t i = 0; i < data.size(); ++i) {
		res += data[i];
	}
	clock_t end = clock();
	_elapsedVector = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Sum: " << res << std::endl;
}

double PmergeMe::getListTime() const {
	return _elapsedList;
}

void PmergeMe::runFordJohnsonList(std::list<int>& data) {
	clock_t start = clock();
	int res = 0;
	for (std::list<int>::const_iterator it = data.begin(); it != data.end(); ++it) {
		res += *it;
	}
	clock_t end = clock();
	_elapsedList = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Sum: " << res << std::endl;
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