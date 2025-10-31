#include "AForm.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _isSigned;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << WHITE BOLD "AForm: " << CYAN BOLD << form.getName()
	   << RESET WHITE " | Signed: " << GREEN BOLD << (form.isSigned() ? "Yes" : "No")
	   << RESET WHITE " | Sign Grade: " << YELLOW BOLD << form.getSignGrade()
	   << RESET WHITE " | Exec Grade: " << MAGENTA BOLD << form.getExecGrade()
	   << RESET;
	return os;
}
