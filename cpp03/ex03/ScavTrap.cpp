/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:00:03 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/05 17:20:47 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	//std::cout << "ScavTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	//std::cout << "ScavTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & other) : ClapTrap(other._name)
{
	//std::cout << "ScavTrap copy constructor called" << std::endl;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & other)
{
	//std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap( void )
{
	//std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "\033[35mScavTrap " << _name << "\033[0m" << "\033[31m attacks " << target << ", causing " << _attackDamage << " points of damage!\033[0m" << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "\033[35mScavTrap " << _name << "\033[0m" << "\033[31m has no hit points left\033[0m" << std::endl;
	else
		std::cout << "\033[35mScavTrap " << _name << "\033[0m" << "\033[31m has no energy points left\033[0m" << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate()
{
	if (_energyPoints <= 0)
		std::cout << "\033[35mScavTrap " << _name << "\033[0m" << "\033[31m has no energy points left\033[0m" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "\033[35mScavTrap " << _name << "\033[0m" << "\033[31m has no hit points left\033[0m" << std::endl;
	else
		std::cout << "\033[35mScavTrap " << _name << "\033[0m" << "\033[32m is now in Gate keeper mode\033[0m" << std::endl;
	_energyPoints--;
}