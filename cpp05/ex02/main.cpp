#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	try {
		std::cout << WHITE BOLD "ShrubberyCreationForm Test" RESET << std::endl;
		Bureaucrat zizou("zizou", 150);
		ShrubberyCreationForm zazie("zazie");
		zizou.signForm(zazie);
		zizou.executeForm(zazie);
	} catch (std::exception &e) {
		std::cout << RED BOLD "Exception: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << WHITE BOLD "RobotomyRequestForm Test" RESET << std::endl;
		Bureaucrat maradona("maradona", 150);
		RobotomyRequestForm macaroni("macaroni");
		maradona.signForm(macaroni);
		maradona.executeForm(macaroni);
	} catch (std::exception &e) {
		std::cout << RED BOLD "Exception: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << WHITE BOLD "PresidentialPardonForm Test" RESET << std::endl;
		Bureaucrat pelé("pelé", 115);
		PresidentialPardonForm ppf("plé");
		pelé.signForm(ppf);
		pelé.executeForm(ppf);
	} catch (std::exception &e) {
		std::cout << RED BOLD "Exception: " << e.what() << RESET << std::endl;
	}
}
