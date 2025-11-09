#include "MutantStack.hpp"

int main()
{
	{
		std::cout << "===== Mutant stack =====" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	{

		std::cout << "\n\n===== Vector stack =====" << std::endl;
	
		std::vector<float> vec1;
		vec1.push_back(5.0f);
		vec1.push_back(17.0f);
		std::cout << vec1.back() << std::endl;
		vec1.pop_back();
		std::cout << vec1.size() << std::endl;
		vec1.push_back(3.0f);
		vec1.push_back(5.0f);
		vec1.push_back(737.0f);
		vec1.push_back(0.0f);
		std::vector<float>::iterator it = vec1.begin();
		std::vector<float>::iterator ite = vec1.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::vector<float> s(vec1);
		return 0;
	}
}