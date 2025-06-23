/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:24:01 by niabraha          #+#    #+#             */
/*   Updated: 2025/06/23 17:03:25 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if (this->_grade > 150)
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

void Bureaucrat::signForm(Form &form) {
	try {
		if (this->_grade <= form.getGradeToSign()) {
			form.beSigned(*this);
			std::cout << this->getName() << CYAN BOLD << " signed " << RESET << form.getName() << std::endl;
		} else {
			std::cout << this->getName() << CYAN BOLD << " couldn't sign " << RESET << form.getName() 
					  << ", because grade is too low." RESET << std::endl;
		}
	} catch (const Form::GradeTooLowException &e) {
		std::cerr << YELLOW BOLD << "Exception caught: " << RESET << e.what() << '\n';
	}
	if (form.getIsSigned())
		std::cout << this->getName() << CYAN BOLD << " successfully signed " << form.getName() << RESET << std::endl;
	else
		std::cout << this->getName() << CYAN BOLD << " failed to sign " << form.getName() << RESET << std::endl;
	
}
