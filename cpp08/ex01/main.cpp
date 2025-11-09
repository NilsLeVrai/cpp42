#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span is: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span is: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span sp1 = Span(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		sp1.addNumber(1212);
		std::cout << "Shortest Span is: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest Span is: " << sp1.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Span sp2(1000);
		std::vector<int> sp2numbers;
		for (int i = 0; i < 1000; i++) {
			sp2numbers.push_back(i);
		}
		sp2.addRange(sp2numbers.begin(), sp2numbers.end());
		std::cout <<"Shortest Span is: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest Span is: "  << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Span sp3(5);
		sp3.addNumber(42);
		std::cout << "Shortest Span is: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest Span is: " << sp3.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Span sp4(10);
		std::list<int> lst;
		for (int i = 0; i < 10; ++i) lst.push_back(i);
		sp4.addRange(lst.begin(), lst.end());
		std::cout << "Shortest Span is: " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest Span is: " << sp4.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
