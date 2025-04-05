/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:12:35 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/05 17:13:47 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	
	//std::cout << "ClapTrap constructor called" << std::endl;
	_name = "";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name){
	
	//std::cout << "ClapTrap constructor called" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const & other){
	
	//std::cout << "ClapTrap copy constructor called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & other){
	
	//std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap( void ){
	
	//std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "\033[33mScavTrap " << _name << "\033[0m" << "\033[31m attacks " << target << ", causing " << _attackDamage << " points of damage!\033[0m" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "\033[33mScavTrap " << _name << "\033[0m" << "\033[31m has no hit points left\033[0m" << std::endl;
	else
		std::cout << "\033[33mScavTrap " << _name << "\033[0m" << "\033[31m has no energy points left\033[0m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){

	if (_hitPoints > 0)
	{
		std::cout << "\033[33mClapTrap " << _name << "\033[0m" << "\033[31m takes " << amount << " points of damage!\033[0m" << std::endl;
		_hitPoints -= amount;
	}
	else
		std::cout << "\033[33mClapTrap " << _name << "\033[0m" << "\033[31m has no hit points left\033[0m" << std::endl;
	if (_hitPoints <= 0)
	{
		std::cout << "\033[33mClapTrap " << _name << "\033[0m" << "\033[31m is dead!\033[0m" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_energyPoints > 0)
	{
		if (_hitPoints > 100)
		{
			std::cout << "\033[32mThat's too much Hit Points! Let's keep it to 100." << "\033[0m" << std::endl;
			_hitPoints = 100;
			std::cout << "\033[33mClapTrap " << _name << "\033[0m" << "\033[32m repairs itself to 100 points!\033[0m" << std::endl;
		}
		else
		std::cout << "\033[33mClapTrap " << _name << "\033[0m" << "\033[32m repairs itself for " << amount << " points!\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[33mClapTrap " << _name << "\033[0m" << "\033[32m has no energy left to be repaired.\033[0m" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
}

std::string ClapTrap::getName(){
	return _name;
}

void ClapTrap::setName(std::string name){
	_name = name;
}