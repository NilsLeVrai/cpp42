/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:22:48 by niabraha          #+#    #+#             */
/*   Updated: 2025/03/05 18:38:53 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fractional_bits = 8;

Fixed::Fixed() : _value(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src) {
	//std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	//std::cout << "Int constructor called" << std::endl;
	this->_value = value << Fixed::_fractional_bits;
}

Fixed::Fixed(const float value) {
	//std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << Fixed::_fractional_bits));
}

int Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat( void ) const {
	//std::cout << "toFloat member function called" << std::endl;
	return (float)this->_value / (1 << Fixed::_fractional_bits);
}

int Fixed::toInt( void ) const {
	//std::cout << "toInt member function called" << std::endl;
	return this->_value >> Fixed::_fractional_bits;
}

bool Fixed::operator>(const Fixed &rhs) const {
	//std::cout << "Comparison operator called >" << std::endl;
	return this->_value > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
	//std::cout << "Comparison operator called <" << std::endl;
	return this->_value < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
	//std::cout << "Comparison operator called >=" << std::endl;
	return this->_value >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
	//std::cout << "Comparison operator called <=" << std::endl;
	return this->_value <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const {
	//::cout << "Comparison operator called ==" << std::endl;
	return this->_value == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
	//std::cout << "Comparison operator called !=" << std::endl;
	return this->_value != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	//std::cout << "Addition operator called" << std::endl;
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	//std::cout << "Subtraction operator called" << std::endl;
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	//std::cout << "Multiplication operator called" << std::endl;
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	//std::cout << "Division operator called" << std::endl;
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++() {
	this->_value++;
	//std::cout << "Pre-incrementation operator called" << std::endl;
	return *this;
}

Fixed Fixed::operator++(int) {
	//std::cout << "Post-incrementation operator called" << std::endl;
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--() {
	//std::cout << "Pre-decrementation operator called" << std::endl;
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	//std::cout << "Post-decrementation operator called" << std::endl;
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) {
	return lhs < rhs ? lhs : rhs;
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs) {
	return lhs < rhs ? lhs : rhs;
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
	return lhs > rhs ? lhs : rhs;
}

const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs) {
	return lhs > rhs ? lhs : rhs;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
