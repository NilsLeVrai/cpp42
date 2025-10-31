#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    Intern  intern;
    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 140);

    const char* formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
        "unknown form"
    };

    for (int i = 0; i < 4; ++i) {
        std::cout << WHITE BOLD << "\n===== Intern creates form: " << CYAN BOLD << formNames[i] << RESET WHITE << " =====" << std::endl;
        AForm* form = intern.makeForm(formNames[i], "Target_" + std::string(formNames[i]));

        if (form) {
            std::cout << *form << std::endl;

            try {
                std::cout << "-> Bob tries to sign the form..." << std::endl;
                bob.signForm(*form);
                std::cout << "-> Bob tries to execute the form..." << std::endl;
                bob.executeForm(*form);
            } catch (const std::exception &e) {
                std::cout << "Exception: " << e.what() << std::endl;
            }

            std::cout << "\n-> Alice (grade 1) signs and executes the form" << std::endl;
            alice.signForm(*form);
            alice.executeForm(*form);

            delete form;
        }
    }
    std::cout << WHITE BOLD << "\n===== End of Intern tests =====" << RESET << std::endl;
	std::cout << WHITE BOLD << "\n===== Subject test =====" << RESET << std::endl;

    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
            delete rrf;
    }
    return 0;
}
