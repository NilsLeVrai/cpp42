/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:57:47 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/06 17:00:56 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {

}

Weapon::~Weapon() {

}

void Weapon::setType(std::string type) {

	this->_type = type;
}

const std::string &Weapon::getType() const {
	
	return (this->_type);
}