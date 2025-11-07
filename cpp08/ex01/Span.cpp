#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::~Span() {}

Span::Span(unsigned int size) : _maxSize(size) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _vec(other._vec) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_vec = other._vec;
	}
	return (*this);
}

void Span::addNumber(const int number) {
	if (_vec.size() >= _maxSize)
		throw SpanIsFullException();
	_vec.push_back(number);
}

int Span::shortestSpan() const {
	if (_vec.size() < 2)
		throw NoSpanFoundException();
	std::vector<int> sortedVec = _vec;
	std::sort(sortedVec.begin(), sortedVec.end());

	int shortestSpan = INT_MAX;
	int tmpSpan;
	for (unsigned int i = 1; i < sortedVec.size() ; ++i) {
		tmpSpan = sortedVec[i] - sortedVec[i - 1];
		if (tmpSpan < shortestSpan) {
			shortestSpan = tmpSpan;
		}
	}	
	return (shortestSpan);
}

int Span::longestSpan() const {
	if (_vec.size() < 2)
		throw NoSpanFoundException();
	int minElement = *std::min_element(_vec.begin(), _vec.end());
	int maxElement = *std::max_element(_vec.begin(), _vec.end());

	return (maxElement - minElement);
}

const char* Span::SpanIsFullException::what() const throw() {
    return "Span is already full.";
}

const char* Span::NoSpanFoundException::what() const throw() {
    return "No span has been found. Less than two numbers.";
}

