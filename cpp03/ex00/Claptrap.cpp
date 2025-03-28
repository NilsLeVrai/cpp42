/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:12:35 by niabraha          #+#    #+#             */
/*   Updated: 2025/03/24 17:53:21 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

ClapTrap::ClapTrap(){
	
	std::cout << "ClapTrap constructor called" << std::endl;
	_name = "";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name){
	
	std::cout << "ClapTrap constructor called" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const & other){
	
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & other){
	
	std::cout << "ClapTrap assignation operator called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap( void ){
	
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	
	if (_hitPoints <= 0)
		std::cout << "You cannot attack because you have no point left" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "You cannot attack because you have no energy left" << std::endl;
	_hitPoints -= _attackDamage;
	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){

	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		_hitPoints = (_hitPoints < 0) ? 0 : _hitPoints;
		if (!_hitPoints)
			std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		_energyPoints -= 1;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout << "Don't hit me, I'm already dead! :(" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	
	if (_hitPoints > 0)
	{
		_hitPoints += amount;
		_hitPoints = (_hitPoints > 10) ? 10 : _hitPoints;
		_energyPoints -= 1;
		std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points!" << std::endl;
	}
	else
		std::cout << "Don't repair me, I'm already dead! :(" << std::endl;
}

void ClapTrap::setName(std::string name){
	
	_name = name;
}

std::string ClapTrap::getName(void){
	
	return _name;
}