#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

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
};