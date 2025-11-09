#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <climits>
#include <iostream>

class Span {

	private:

		unsigned int		_maxSize;
		std::vector<int>	_vec;

	public:

		Span();
		Span(unsigned int _maxSize);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();

		void addNumber(const int number);
		int shortestSpan() const;
		int longestSpan() const;
		void printSpan() const;

		class SpanIsFullException : public std::exception {
			const char* what() const throw();
		};
		class NoSpanFoundException : public std::exception {
			const char* what() const throw();
		};

		template <typename InputIterator>
		void addRange(InputIterator begin, InputIterator end) {
			size_t count = std::distance(begin, end);
			if (_vec.size() + count > _maxSize)
				throw SpanIsFullException();
			_vec.insert(_vec.end(), begin, end);
		}
};