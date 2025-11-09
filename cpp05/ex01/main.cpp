#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <stdexcept>

int main()
{
	try {
		std::cout << WHITE BOLD "Basic Form creation tests\n";
		Form form1("Form n°1", 75, 50);
		std::cout << form1 << std::endl;

		Form form2("Form n°2", 1, 1);
		std::cout << form2 << std::endl;

		std::cout << WHITE BOLD "\nTrying to create invalid forms\n";
		try {
			Form invalidHigh("Invalid High", 0, 10); // Exception : "Grade too high"
		}
		catch (const std::exception &error) {
			std::cout << YELLOW BOLD "Exception caught: " RESET << error.what() << std::endl;
		}

		try {
			Form invalidLow("Invalid Low", 160, 160); // Exception : "Grade too low"
		}
		catch (const std::exception &error) {
			std::cout << YELLOW BOLD "Exception caught: " RESET << error.what() << std::endl;
		}
	}
	catch (const std::exception &error) {
		std::cout << YELLOW BOLD "Exception caught: " RESET << error.what() << '\n';
	}

	std::cout << WHITE BOLD "\nSigning tests\n";

	try {
		Bureaucrat ceo("CEO", 1);
		Bureaucrat intern("Intern", 150);
		Bureaucrat employee("employee", 70);

		Form contract("Contract", 100, 100);
		Form permit("Permit", 50, 25);

		std::cout << contract << std::endl;
		std::cout << permit << std::endl;

		std::cout << WHITE BOLD "\nIntern tries to sign\n" RESET;
		intern.signForm(contract);
		intern.signForm(permit);

		std::cout << WHITE BOLD "\nemployee tries to sign\n" RESET;
		employee.signForm(contract);
		employee.signForm(permit);

		std::cout << WHITE BOLD "\nCEO signs everything\n" RESET;
		ceo.signForm(contract);
		ceo.signForm(permit);

		std::cout << WHITE BOLD "\nFinal state of forms\n" RESET;
		std::cout << contract << std::endl;
		std::cout << permit << std::endl;
	}
	catch (const std::exception &error) {
		std::cout << YELLOW BOLD "Exception caught: " RESET << error.what() << '\n';
	}

	std::cout << WHITE BOLD "\nEdge cases\n" RESET;
	try {
		Bureaucrat elite("Elite", 5);
		Form eliteForm("Elite Only", 5, 5);

		std::cout << eliteForm << std::endl;
		elite.signForm(eliteForm);  // exact grade match
		std::cout << eliteForm << std::endl;
	}
	catch (const std::exception &error) {
		std::cout << YELLOW BOLD "Exception caught: " RESET << error.what() << '\n';
	}


	std::cout << WHITE BOLD "\nDouble signing test\n" RESET;
	try {
		Bureaucrat boss("BabyBoss", 1);
		Form doubleSign("DoubleSign", 50, 50);

		std::cout << doubleSign << std::endl;

		boss.signForm(doubleSign);
		boss.signForm(doubleSign);
		
		std::cout << doubleSign << std::endl;
	}
	catch (const std::exception &error) {
		std::cout << YELLOW BOLD "Exception caught: " RESET << error.what() << '\n';
	}

	std::cout << WHITE BOLD "\nTriggering GradeTooHighException\n" RESET;
	try {
		Bureaucrat daniel("Daniel", 1);
		std::cout << daniel << std::endl;
		daniel.incrementGrade();
	}
	catch (const std::exception &error) {
		std::cout << YELLOW BOLD "Exception caught: " RESET << error.what() << std::endl;
	}

	std::cout << WHITE BOLD "\nCreating an invalid Bureaucrat\n" RESET;
	try {
		Bureaucrat esteban("Esteban", 1212);
	}
	catch (const std::exception &error) {
		std::cout << YELLOW BOLD "Exception caught: " RESET << error.what() << std::endl;
	}

	return 0;
}
