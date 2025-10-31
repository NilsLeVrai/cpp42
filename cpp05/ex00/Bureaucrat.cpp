#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
	// std::cout << "Constructor" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	// std::cout << "Destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {

	// std::cout << "Copy constructor" << std::endl;
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	// std::cout << "Copy assignement operator" << std::endl;
	if (this == &src)
		return *this;
	this->_grade = src.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	// std::cout << "Constructeur with parameters" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
