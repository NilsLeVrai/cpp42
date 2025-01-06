/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:02:16 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/06 15:21:22 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->_name = name;
	std::cout << "Zombie" << this->_name << " is born" << std::endl;
}

Zombie::Zombie() {
	std::cout << "Zombie" << this->_name << " is born" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->_name << " has been destroyed" << std::endl;
}

void Zombie::announce( void ) const {
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}
