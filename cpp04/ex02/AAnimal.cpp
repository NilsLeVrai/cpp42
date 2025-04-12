/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:30:50 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/12 16:47:06 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string type) : _type(type) {
	std::cout << "AAnimal constructor called with type: " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) : _type(src._type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void AAnimal::makeSound() const {
	std::cout << "AAnimal sound" << std::endl;
}

std::string AAnimal::getType() const {
	return this->_type;
}
