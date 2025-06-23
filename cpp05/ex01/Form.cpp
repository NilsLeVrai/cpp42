/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:09:48 by niabraha          #+#    #+#             */
/*   Updated: 2025/06/23 17:03:14 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Form::Form() : _name("default"), _is_signed(false), _grade_to_sign(150), _grade_to_exec(150) {
	// std::cout << "Constructor" << std::endl;
}

Form::~Form() {
	// std::cout << "Destructor" << std::endl;
}

Form::Form(const Form &src) : _name(src.getName()), _is_signed(src._is_signed), _grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec) {
	// std::cout << "Copy constructor" << std::endl;
}

Form &Form::operator=(const Form &src) {
	// std::cout << "Copy assignement operator" << std::endl;
	if (this == &src)
		return *this;
	this->_is_signed = src._is_signed;
	return *this;
}

Form::Form(const std::string _name, int _grade_to_sign, int _grade_to_exec) : _name(_name), _is_signed(false), _grade_to_sign(_grade_to_sign), _grade_to_exec(_grade_to_exec) {
	// std::cout << "Constructeur with parameters" << std::endl;
	if (this->_grade_to_sign < 1 || this->_grade_to_exec < 1)
		throw Form::GradeTooHighException();
	if (this->_grade_to_sign > 150 || this->_grade_to_exec > 150)
		throw Form::GradeTooLowException();
}

std::string Form::getName() const {
	return std::string(MAGENTA BOLD) + this->_name + RESET;
}

int Form::getGradeToSign() const {
	return this->_grade_to_sign;
}

int Form::getGradeToExec() const {
	return this->_grade_to_exec;
}

bool Form::getIsSigned() const {
	return this->_is_signed;
}

void Form::beSigned(const Bureaucrat &src) {
	if (src.getGrade() > this->_grade_to_sign)
		throw Form::GradeTooLowException();
	this->_is_signed = true;
	std::cout << src.getName() << CYAN BOLD << " signed " <<  RESET << this->getName() << std::endl;
}

