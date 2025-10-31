#pragma once

#define BOLD_BLUE    "\033[1;34m"
#define BOLD_RED     "\033[1;31m"
#define BOLD_GREEN   "\033[1;32m"
#define BOLD_YELLOW  "\033[1;33m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN    "\033[1;36m"
#define BOLD_WHITE   "\033[1;37m"
#define BOLD_BLACK   "\033[1;30m"
#define RESET        "\033[0m"

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {

	private:

		T* 				_elements;
		unsigned int	_size;

	public:
	
		Array() : _elements(new T[0]), _size(0) {}

		~Array() {
			delete[] _elements;
		}
		Array(const unsigned int n) : _elements(new T[n]()), _size(n) {}

		Array(const Array& other) : _elements(new T[other._size]), _size(other._size) {
			for (unsigned int i = 0; i < _size; i++)
				_elements[i] = other._elements[i];
		}

		Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] _elements;
				_size = other._size;
				_elements = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_elements[i] = other._elements[i];
			}
			return *this;
		}


		T& operator[](unsigned int index) {
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _elements[index];
		}

		const T& operator[](unsigned int index) const {
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _elements[index];
		}

		unsigned int size() const {
			return _size;
		}
};