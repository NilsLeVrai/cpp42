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

template <typename T>
void iter(T *array, const unsigned int length, void (*func)(T &))
{
	for (unsigned int i = 0; i < length; i++)
		func(array[i]);
}
template <typename T>
void iter(const T *array, const unsigned int length, void (*func)(const T &))
{
	for (unsigned int i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void print(T &element)
{
	std::cout << "[" << element << "] ";
}