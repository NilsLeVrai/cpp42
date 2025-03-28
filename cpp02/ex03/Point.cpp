/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:57:12 by niabraha          #+#    #+#             */
/*   Updated: 2025/03/09 23:01:03 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x_value(0), y_value(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point &src) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Point &Point::operator=(const Point &src) {
	//std::cout << "Assignation operator called" << std::endl;
	if (this != &src) {
		this->x_value = src.x_value;
		this->y_value = src.y_value;
	}
	return *this;
}

Point::~Point() {
	//std::cout << "Destructor called" << std::endl;
}

Point::Point(const float x, const float y) : x_value(Fixed(x)), y_value(Fixed(y)) {
	//std::cout << "Float constructor called" << std::endl;
}

Point::Point(const Fixed &x, const Fixed &y) : x_value(x), y_value(y) {
	//std::cout << "Fixed constructor called" << std::endl;
}

float Point::getX() const {
	return this->x_value.toFloat();
}

float Point::getY() const {
	return this->y_value.toFloat();
}

bool Point::operator==(const Point &rhs) const {
	return this->x_value == rhs.x_value && this->y_value == rhs.y_value;
}


