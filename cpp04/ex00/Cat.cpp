/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:33:14 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/12 16:52:29 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
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