/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:00:54 by niabraha          #+#    #+#             */
/*   Updated: 2025/03/24 18:01:17 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>

class ScavTrap
{
	private:
		unsigned int        _hit_points;
		unsigned int        _max_hit_points;
		unsigned int        _energy_points;
		unsigned int        _max_energy_points;
		unsigned int        _level;
		std::string         _name;
		unsigned int        _melee_attack_damage;
		unsigned int        _ranged_attack_damage;
		unsigned int        _armor_damage_reduction;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap();
		ScavTrap & operator=(ScavTrap const & rhs);
		void        rangedAttack(std::string const & target);
		void        meleeAttack(std::string const & target);
		void        takeDamage(unsigned int amount);
		void        beRepaired(unsigned int amount);
		void        challengeNewcomer(void);
};

#endif