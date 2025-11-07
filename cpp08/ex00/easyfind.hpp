#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <list>

template <typename T>
typename T::iterator easyfind(T& type, int value) {
    typename T::iterator it = std::find(type.begin(), type.end(), value);
    if (it == type.end())
        throw std::out_of_range("Element not found in this container");
    return it;
}

//const ^^