/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:06:19 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/06 14:56:56 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	this->_name = name;
}

Zombie::~Zombie() {
	std::cout << this->_name << " has been destroyed" << std::endl;
}

void Zombie::announce( void ) const {
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
