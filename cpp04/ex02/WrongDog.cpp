/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:09:18 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/12 17:42:06 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAAnimal()
{
	std::cout << "Default constructor called for WrongDog" << std::endl;
}

WrongDog::WrongDog(const WrongDog &copy) : WrongAAnimal(copy)
{
	std::cout << "Copy constructor called for WrongDog" << std::endl;
	*this = copy;
}

WrongDog &WrongDog::operator=(const WrongDog &copy)
{
	std::cout << "Copy assignment operator called for WrongDog" << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}

WrongDog::~WrongDog()
{
	std::cout << "Destructor called for WrongDog" << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << "WrongDog sound" << std::endl;
}