#pragma once

#include <algorithm>

template <typename T>
typename T::const_iterator (T& type, int value) {
    typename T::iterator it = type.begin();
    for (; it != type.end(); it++) {
        if (value == *it)
            break;
    }
    return (it);
}