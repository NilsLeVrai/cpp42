/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:34:04 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/07 22:35:14 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	//std::cout << "FragTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	//std::cout << "FragTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}
FragTrap::FragTrap(FragTrap const & other) : ClapTrap(other)
{
	//std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}
FragTrap& FragTrap::operator=(FragTrap const & other)
{
	//std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap( void )
{
	//std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "FragTrap " << _name << " is dead and cannot attack." << std::endl;
	else
		std::cout << "FragTrap " << _name << " is out of energy and cannot attack." << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	if (_hitPoints > 0 && _energyPoints > 0)
		std::cout << "FragTrap " << _name << " wants to high five!" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "FragTrap " << _name << " is dead and cannot ask for a high five :(" << std::endl;
	else
		std::cout << "FragTrap " << _name << " is out of energy and cannot request a high five." << std::endl;
}