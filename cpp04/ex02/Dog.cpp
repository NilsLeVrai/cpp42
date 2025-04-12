/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:33:14 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/12 17:42:06 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : AAnimal(src) {
	*this = src;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Miaouuu miaouuu" << std::endl;
}

void Dog::setBrainIdeas(std::string ideas) {
	for (int i = 0; i < 100; i++) {
		this->_brain->setIdea(i, ideas);
	}
}

void Dog::setBrainIdea(int index, std::string idea) {
	if (index >= 0 && index < 100) {
		this->_brain->setIdea(index, idea);
	} else {
		std::cout << "Index out of range" << std::endl;
	}
}

void Dog::printIdeas() const {
	std::cout << "Ideas = ";
	for (int i = 0; i < 100; i++) {
		std::cout << i << ":" << _brain->getIdea(i);
		std::cout << " ";
	}
	std::cout << std::endl;
}

