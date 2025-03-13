/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:14:22 by niabraha          #+#    #+#             */
/*   Updated: 2025/03/13 15:42:46 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ClapTrap {

	private:
		int 		_hitPoints;
		int 		_energyPoints;
		int 		_attackDamage;
		std::string _name;

	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & other);
		ClapTrap& operator=(ClapTrap const & other);
		~ClapTrap( void );
	
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};