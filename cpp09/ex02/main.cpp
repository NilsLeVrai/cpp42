#include "PmergeMe.hpp"

int main () {

	if (argc < 2) {
		std::std::cout << "Usage: " << argv[0] << " <list of positive integers>" << std::endl;
		return 1;
	}

	PmergeMe pmergeMe;
	pmergeMe.insertData(argv);
	pmergeMe.mergeInsertSortVector(0, pmergeMe.getVectorSize() - 1);
	pmergeMe.mergeInsertSortList(pmergeMe.getListBegin(), pmergeMe.getListEnd());
	pmergeMe.printVector();
	pmergeMe.printList();

	return 0;
}