/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:14:17 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/08 17:25:36 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void ) {
	ScavTrap	clubyTrap("Cluby");
	FragTrap	ahansTrap("Ahans");

	std::cout << std::endl;
	ahansTrap.highFivesGuys();
	clubyTrap.attack("Ahans");
	ahansTrap.takeDamage(20);
	clubyTrap.guardGate();
	ahansTrap.attack("Cluby");
	clubyTrap.takeDamage(30);
	ahansTrap.attack("Cluby");
	clubyTrap.takeDamage(30);
	ahansTrap.attack("Cluby");
	clubyTrap.takeDamage(30);
	clubyTrap.beRepaired(20);
	ahansTrap.attack("Cluby");
	clubyTrap.takeDamage(30);
	clubyTrap.beRepaired(20);
	ahansTrap.attack("Cluby");
	clubyTrap.guardGate();
	ahansTrap.highFivesGuys();
	std::cout << std::endl;
	return (0);
}