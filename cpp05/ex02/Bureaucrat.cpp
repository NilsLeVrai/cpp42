#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(){
	// std::cout << "Constructor" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	// std::cout << "Destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this == &src)
		return *this;
	this->_grade = src.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName() const {
	return std::string(MAGENTA BOLD) + this->_name + RESET;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << GREEN BOLD << _name << RESET " signed " CYAN BOLD << form.getName() << RESET << std::endl;
	} catch (const std::exception &e) {
		std::cout << YELLOW BOLD << _name << RESET " couldn’t sign " CYAN BOLD
		          << form.getName() << RESET " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low";
}

void Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);
		std::cout << GREEN BOLD << this->_name << RESET " executed " CYAN BOLD << form.getName() << RESET << std::endl;
	} catch (const std::exception &e) {
		std::cout << YELLOW BOLD << this->_name << RESET " couldn’t execute " CYAN BOLD
		          << form.getName() << RESET " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << MAGENTA BOLD << bureaucrat.getName() << RESET CYAN " | grade: " GREEN
	   << bureaucrat.getGrade() << RESET;
	return os;
}
