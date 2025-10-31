#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();

	std::ofstream out((_target + "_shrubbery").c_str());
	if (!out)
		throw std::runtime_error("Failed to create shrubbery file");

	out << "       _-_\n"
	       "    /~~   ~~\\\n"
	       " /~~         ~~\\\n"
	       "{               }\n"
	       " \\  _-     -_  /\n"
	       "   ~  \\\\ //  ~\n"
	       "_- -   | | _- _\n"
	       "  _ -  | |   -_\n"
	       "      // \\\\\n";

	out.close();
}
