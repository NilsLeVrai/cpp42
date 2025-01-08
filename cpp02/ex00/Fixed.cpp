/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:22:40 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/08 18:09:21 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) {
	
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {

	std::cout << "Copy constructor called" << std::endl;
}



Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	
	std::cout << "getRawBits member function called" << std::endl;
	return 0;
}

void Fixed::setRawBits( int const raw) {
	this->_value = raw;
	std::cout << raw << "qwqw" << std::endl;
}