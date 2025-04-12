/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:33:14 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/12 17:42:06 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : AAnimal(src) {
	*this = src;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Miaouuu miaouuu" << std::endl;
}

void Cat::setBrainIdeas(std::string ideas) {
	for (int i = 0; i < 100; i++) {
		this->_brain->setIdea(i, ideas);
	}
}

void Cat::setBrainIdea(int index, std::string idea) {
	if (index >= 0 && index < 100) {
		this->_brain->setIdea(index, idea);
	} else {
		std::cout << "Index out of range" << std::endl;
	}
}

void Cat::printIdeas() const {
	std::cout << "Ideas = ";
	for (int i = 0; i < 100; i++) {
		std::cout << i << ":" << _brain->getIdea(i);
		std::cout << " ";
	}
	std::cout << std::endl;
}