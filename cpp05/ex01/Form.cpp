#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _isSigned;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (_isSigned) {
		throw Form::AlreadySignedException();
	}
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << WHITE BOLD "Form: " << CYAN BOLD << form.getName()
	   << RESET WHITE " | Signed: " << GREEN BOLD << (form.isSigned() ? "Yes" : "No")
	   << RESET WHITE " | Sign Grade: " << YELLOW BOLD << form.getSignGrade()
	   << RESET WHITE " | Exec Grade: " << MAGENTA BOLD << form.getExecGrade()
	   << RESET;
	return os;
}
