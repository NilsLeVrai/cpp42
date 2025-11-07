#include "easyfind.hpp"

int main() {
    
    std::vector<int> vec1;

    vec1.push_back(1);
    vec1.push_back(10);
    vec1.push_back(-5);

    std::list<char> lst1;

    lst1.push_back('a');
    lst1.push_back('b');
    lst1.push_back('c');

    try {
        std::vector<int>::iterator it1 = easyfind(vec1, 10);
        std::cout << "Value found: " << *it1 << std::endl;

        std::vector<int>::iterator it2 = easyfind(vec1, 0);
        std::cout << "Value found: " << *it2 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::list<char>::iterator it3 = easyfind(lst1, 'b');
        std::cout << "Value found: " << *it3 << std::endl;

        std::list<char>::iterator it4 = easyfind(lst1, 'j');
        std::cout << "Value found: " << *it4 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}