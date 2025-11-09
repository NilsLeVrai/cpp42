#include "Bureaucrat.hpp"

#include <iostream>
#include <stdexcept>

int main()
{
    try {
		std::cout << WHITE BOLD "Basic tests until too high grade\n";
        Bureaucrat a("niabraha", 1);
        std::cout << a.getName() << CYAN BOLD << ", bureaucrat grade " << GREEN BOLD << a.getGrade() << RESET << std::endl;
        
		Bureaucrat b("niabraha", 150);
        std::cout << b.getName() << CYAN BOLD  << ", bureaucrat grade " << GREEN BOLD << b.getGrade() << RESET << std::endl;

        Bureaucrat c("niabraha", 100);
        std::cout << c.getName() << CYAN BOLD << ", bureaucrat grade " << GREEN BOLD << c.getGrade() << RESET << std::endl;

        Bureaucrat d("niabraha", -50);  // Exception : "Grade too high"
        std::cout << d.getName() << CYAN BOLD << ", bureaucrat grade " << GREEN BOLD << d.getGrade() << RESET << std::endl;
	}
	catch (const std::exception &error) {
		std::cout << YELLOW BOLD<< "Exception caught: " << RESET << error.what() << '\n';
	}
	try {
		std::cout << WHITE BOLD "\nBasic tests until too low grade\n";
        Bureaucrat e("niabraha", 10);
        std::cout << e.getName() << CYAN BOLD << ", bureaucrat grade " << GREEN BOLD << e.getGrade() << RESET << std::endl;

        Bureaucrat f("niabraha", 151);  // Exception : "Grade too low"
        std::cout << f.getName() << CYAN BOLD << ", bureaucrat grade " << GREEN BOLD << f.getGrade() << RESET << std::endl;
	}
	catch (const std::exception &error) {
		std::cout << YELLOW BOLD<< "Exception caught: " << RESET << error.what() << '\n';
	}
	
	try {
		std::cout << WHITE BOLD "\nIncrementing until too high\n";
        Bureaucrat j("niabraha", 3);
		j.incrementGrade();
		std::cout << j.getName() << CYAN BOLD << ", bureaucrat grade " << GREEN BOLD << j.getGrade() << RESET << std::endl;
		
		 Bureaucrat k("niabraha", 1); // Exception : "Grade too high" 1 --> 0
		k.incrementGrade();
		std::cout << k.getName() << CYAN BOLD << ", bureaucrat grade " << GREEN BOLD << k.getGrade() << RESET << std::endl;
	}
	catch (const std::exception &error) {
		std::cout << YELLOW BOLD<< "Exception caught: " << RESET << error.what() << '\n';
	}

	try {
		std::cout << WHITE BOLD "\nIncrementing until too low\n";
		Bureaucrat m("niabraha", 15);
		m.decrementGrade();
		std::cout << m.getName() << CYAN BOLD << ", bureaucrat grade " << GREEN BOLD << m.getGrade() << RESET << std::endl;
		
		Bureaucrat l("niabraha", 150);
		l.decrementGrade();
		std::cout << l.getName() << CYAN BOLD << ", bureaucrat grade " << GREEN BOLD << l.getGrade() << RESET << std::endl;
	}
	catch (const std::exception &error) {
		std::cout << YELLOW BOLD<< "Exception caught: " << RESET << error.what() << '\n';
	}
}
