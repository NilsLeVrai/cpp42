/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:45:45 by niabraha          #+#    #+#             */
/*   Updated: 2025/03/10 11:18:47 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {}

Harl::~Harl( void ) {}

void Harl::_debug( void ) const {

	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;

}

void Harl::_info( void ) const {

	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;

}

void Harl::_warning( void ) const {

	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;

}

void Harl::_error( void ) const {

	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable. I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level) {

	std::string messages[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t findLevel = -1;

	for (int i = 0; i <= 4; i++) {
		if (messages[i] == level) {
			findLevel = i;
			break ;
		}
	}
	
	switch (findLevel) 
	{
		case 0:
			this->_debug();
		case 1:
			this->_info();
		case 2:
			this->_warning();
		case 3:
		{
			this->_error();
			break ;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}
