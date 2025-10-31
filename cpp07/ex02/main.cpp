#include "Array.hpp"

int main() {

	try {

		std::cout << BOLD_MAGENTA << "--- INTEGERS ---\n" << RESET << std::endl;
		Array<int> intArray(10);

		for (unsigned int i = 0; i < intArray.size(); i++) {
			intArray[i] = i * 10;
		}

		for (unsigned int i = 0; i < intArray.size(); i++) {
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
		}
		
		std::cout << intArray[23] << std::endl; //Error here

		std::cout << std::endl << BOLD_CYAN << "--- STRINGS ---\n" << RESET << std::endl;
	
		Array<std::string> strArray(5);
		strArray[0] = "Hydrogen";
		strArray[1] = "Helium";
		strArray[2] = "Lithium";
		strArray[3] = "Beryllium";
		strArray[4] = "Carbon";
		for (unsigned int i = 0; i < strArray.size(); i++)
			std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;


		//std::cout << strArray[50] << std::endl; //Error here
	} catch (const std::out_of_range& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}