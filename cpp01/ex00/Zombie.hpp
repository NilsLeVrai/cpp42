/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:41:06 by niabraha          #+#    #+#             */
/*   Updated: 2024/12/28 17:55:34 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie {

	public:
		Zombie(std::string name);
		~Zombie();
		void announce( void ) const;
		
	private:
		std::string _name;
};

Zombie* newZombie( std::string name);
void randomChump( std::string name);
