/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:24:01 by niabraha          #+#    #+#             */
/*   Updated: 2025/05/12 16:05:46 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
	std::cout << "constructeur des familles" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "destructeur des familles" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {

	std::cout << "copieur des familles" << std::endl;
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &src) {
	std::cout << "operateur d'assignation des familles" << std::endl;
	if (this == &src)
		return *this;
	this->_grade = src.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "constructeur avec parametres des familles" << std::endl;
	if (this->_grade < 1)
		throw std::out_of_range("Grade too high");
	if (this->_grade > 150)
		throw std::out_of_range("Grade too low");
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade <= 1)
		throw std::out_of_range("Grade too high");
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade >= 150)
		throw std::out_of_range("Grade too low");
	else
		this->_grade++;
}
