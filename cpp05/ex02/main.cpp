#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	srand(time(NULL));

	try {
		Bureaucrat boss("Boss", 1);
		Bureaucrat mid("Mid", 70);
		Bureaucrat intern("Intern", 160);

		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << WHITE BOLD "\n=== Signing phase ===\n" RESET;
		boss.signForm(shrub);
		boss.signForm(robot);
		boss.signForm(pardon);

		std::cout << WHITE BOLD "\n=== Execution phase ===\n" RESET;
		boss.executeForm(shrub);
		boss.executeForm(robot);
		boss.executeForm(pardon);

		std::cout << WHITE BOLD "\n=== Low-rank bureaucrat tries ===\n" RESET;
		intern.executeForm(pardon);
	}
	catch (const std::exception &e) {
		std::cerr << YELLOW BOLD "Exception caught: " RESET << e.what() << std::endl;
	}
}
