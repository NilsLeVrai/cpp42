// PmergeMe.cpp
#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <ctime>        // pour clock()
#include <iterator>

// --- constructeur / destructeur / opérateurs
PmergeMe::PmergeMe() {
    jacobstahlVector();
    jacobstahlList();
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _vectorData(other._vectorData),
      _listData(other._listData),
      _elapsedVector(other._elapsedVector),
      _elapsedList(other._elapsedList),
      _jacobstahlVector(other._jacobstahlVector),
      _jacobstahlList(other._jacobstahlList)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _listData = other._listData;
        _elapsedVector = other._elapsedVector;
        _elapsedList = other._elapsedList;
        _jacobstahlVector = other._jacobstahlVector;
        _jacobstahlList = other._jacobstahlList;
    }
    return *this;
}


// --- Jacobsthal en vector
void PmergeMe::jacobstahlVector() {
    _jacobstahlVector.clear();
    _jacobstahlVector.push_back(0);
    _jacobstahlVector.push_back(1);
    for (size_t i = 2; i < 50; ++i) {
        size_t un = _jacobstahlVector[i - 1] + 2 * _jacobstahlVector[i - 2];
        _jacobstahlVector.push_back(un);
    }
}

// --- Jacobsthal en list
void PmergeMe::jacobstahlList() {
    _jacobstahlList.clear();
    _jacobstahlList.push_back(0);
    _jacobstahlList.push_back(1);

    size_t u1 = 0;
    size_t u2 = 1;
    for (size_t i = 2; i < 50; ++i) {
        size_t un = u2 + 2 * u1;
        _jacobstahlList.push_back(un);
        u1 = u2;
        u2 = un;
    }
}


// --- ordre d’insertion Jacobsthal
std::vector<size_t> PmergeMe::insertVector(size_t pendSize) {
    std::vector<size_t> order;
    if (pendSize == 0) return order;

    order.push_back(0);
    if (pendSize == 1) return order;

    size_t k = 2;
    while (order.size() < pendSize) {
        size_t j;
        if (k < _jacobstahlVector.size()) j = _jacobstahlVector[k];
        else j = pendSize;

        size_t start = 0;
        if (j == 0) start = 0;
        else start = (j - 1 < pendSize - 1 ? j - 1 : pendSize - 1);

        size_t end = order.size();

        for (int i = (int)start; i >= (int)end; --i) {
            if ((size_t)i < pendSize) {
                order.push_back((size_t)i);
                if (order.size() >= pendSize) break;
            }
        }
        ++k;
    }

    return order;
}


// --- merge Ford–Johnson pour vector
std::vector<int> PmergeMe::mergeVector(const std::vector<int>& vec) {
    size_t n = vec.size();
    if (n <= 1)
        return vec;

    bool hasAlone = false;
    int alone = 0;
    size_t limit = (n / 2) * 2;

    if (n % 2 != 0) {
        hasAlone = true;
        alone = vec[n - 1];
    }

    // former les paires
    std::vector< std::pair<int,int> > pairs;
    for (size_t i = 0; i < limit; i += 2) {
        int a = vec[i];
        int b = vec[i + 1];
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        pairs.push_back(std::make_pair(a,b));
    }

    // extraire les grands
    std::vector<int> sortedMains;
    sortedMains.reserve(pairs.size() + (hasAlone ? 1 : 0));
    for (size_t i = 0; i < pairs.size(); ++i)
        sortedMains.push_back(pairs[i].second);

    // tri récursif
    sortedMains = mergeVector(sortedMains);

    // extraire les petits
    std::vector<int> pendMains;
    pendMains.reserve(pairs.size());
    for (size_t i = 0; i < pairs.size(); ++i)
        pendMains.push_back(pairs[i].first);

    // ordre Jacobsthal
    std::vector<size_t> order = insertVector(pendMains.size());

    // insertion
    for (size_t idx = 0; idx < order.size(); ++idx) {
        if (order[idx] >= pendMains.size()) continue;

        int valueToInsert = pendMains[order[idx]];
        std::vector<int>::iterator it =
            std::lower_bound(sortedMains.begin(), sortedMains.end(), valueToInsert);

        sortedMains.insert(it, valueToInsert);
    }

    // élément isolé
    if (hasAlone) {
        std::vector<int>::iterator it =
            std::lower_bound(sortedMains.begin(), sortedMains.end(), alone);
        sortedMains.insert(it, alone);
    }

    return sortedMains;
}


// --- version list
std::list<int> PmergeMe::mergeList(std::list<int> lst) {
    size_t n = lst.size();
    if (n <= 1) return lst;

    bool hasAlone = false;
    int alone = 0;

    if (n % 2 != 0) {
        hasAlone = true;
        alone = lst.back();
        lst.pop_back();
    }

    std::list<int> mains;
    std::vector<int> pendMains;

    std::list<int>::iterator it = lst.begin();
    while (it != lst.end()) {
        std::list<int>::iterator it1 = it++;
        if (it == lst.end()) break;
        std::list<int>::iterator it2 = it++;

        int a = *it1;
        int b = *it2;

        if (a <= b) {
            pendMains.push_back(a);
            mains.push_back(b);
        } else {
            pendMains.push_back(b);
            mains.push_back(a);
        }
    }

    mains = mergeList(mains);

    std::vector<size_t> order = insertVector(pendMains.size());

    for (size_t idx = 0; idx < order.size(); ++idx) {
        if (order[idx] >= pendMains.size()) continue;

        int valueToInsert = pendMains[order[idx]];

        std::list<int>::iterator pos = mains.begin();
        while (pos != mains.end() && *pos < valueToInsert)
            ++pos;

        mains.insert(pos, valueToInsert);
    }

    if (hasAlone) {
        std::list<int>::iterator pos = mains.begin();
        while (pos != mains.end() && *pos < alone)
            ++pos;
        mains.insert(pos, alone);
    }

    return mains;
}


// --- timings C++98 avec clock()

double PmergeMe::getVectorTime() const { return _elapsedVector; }
double PmergeMe::getListTime() const { return _elapsedList; }


void PmergeMe::runFordJohnsonVector(std::vector<int>& data) {
    clock_t start = clock();

    _vectorData = mergeVector(data);

    clock_t end = clock();

    _elapsedVector = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;

    data = _vectorData;
}


void PmergeMe::runFordJohnsonList(std::list<int>& data) {
    clock_t start = clock();

    _listData = mergeList(data);

    clock_t end = clock();

    _elapsedList = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;

    data = _listData;
}


// --- optionnel
int PmergeMe::calculateLeastOperations(int size) {
    int sum = 0;
    for (int i = 1; i <= size; ++i) {
        double value = (3.0 / 4.0) * i;
        sum += (int)std::ceil(std::log2(value));
    }
    return sum;
}
