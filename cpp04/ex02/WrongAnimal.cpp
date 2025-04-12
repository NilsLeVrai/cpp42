/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:40:34 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/12 16:48:42 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAAnimal::WrongAAnimal() : _type("WrongAAnimal")
{
	std::cout << "Default constructor called for WrongAAnimal" << std::endl;
}
WrongAAnimal::WrongAAnimal(std::string type) : _type(type)
{
	std::cout << "Constructor called for WrongAAnimal with type: " << type << std::endl;
}
WrongAAnimal::WrongAAnimal(const WrongAAnimal &src)
{
	std::cout << "Copy constructor called for WrongAAnimal" << std::endl;
	*this = src;
}

WrongAAnimal::~WrongAAnimal()
{
	std::cout << "Destructor called for WrongAAnimal" << std::endl;
}

WrongAAnimal &WrongAAnimal::operator=(const WrongAAnimal &rhs)
{
	std::cout << "Assignment operator called for WrongAAnimal" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}

void WrongAAnimal::makeSound() const
{
	std::cout << "WrongAAnimal sound" << std::endl;
}

std::string WrongAAnimal::getType() const
{
	return this->_type;
}