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
	//merge
	//insert
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
	//merge
	//insert
	clock_t end = clock();
	_elapsedList = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Sum: " << res << std::endl;
}

void PmergeMe::jacobstahlList() {

	_jacobstahlList.clear();
	_jacobstahlList.push_back(0);
	_jacobstahlList.push_back(1);

	size_t u1 = 0;
	size_t u2 = 1;
	for (size_t i = 2; i < 35; ++i) {
		size_t un = u2 + 2 * u1;
		_jacobstahlList.push_back(un);
		u1 = u2;
		u2 = un;
	}
	if (!_jacobstahlList.empty()) { // ?
		_jacobstahlList.pop_front();
	}
	if (!_jacobstahlList.empty()) {
		_jacobstahlList.pop_front();
	}
}

void PmergeMe::jacobstahlVector() {

	_jacobstahlVector.clear();
	_jacobstahlVector.push_back(0);
	_jacobstahlVector.push_back(1);

	for (size_t i = 2; i < 35; i++) {
		size_t un = _jacobstahlVector[i - 1] + 2 * _jacobstahlVector[i - 2];
		_jacobstahlVector.push_back(un);
	}

	_jacobstahlVector.erase(_jacobstahlVector.begin()); // ?
	_jacobstahlVector.erase(_jacobstahlVector.begin()); // ?
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