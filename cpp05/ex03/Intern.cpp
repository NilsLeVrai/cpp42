#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &) {}
Intern &Intern::operator=(const Intern &) { return *this; }
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* forms[3];
	try {
		forms[0] = new ShrubberyCreationForm(target);
		forms[1] = new RobotomyRequestForm(target);
		forms[2] = new PresidentialPardonForm(target);
	} catch (std::bad_alloc &e) {
		for (int i = 0; i < 3; i++)
			delete forms[i];
		std::cout << "Intern failed to create forms: " << e.what() << std::endl;
		return NULL;
	}

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			for (int j = 0; j < 3; j++)
				if (i != j) delete forms[j];
			return forms[i];
		}
	}

	std::cout << "Intern could not find form named \"" << formName << "\"." << std::endl;
	for (int i = 0; i < 3; i++)
		delete forms[i];
	return NULL;
}
