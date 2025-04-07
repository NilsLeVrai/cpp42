/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:10:21 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/07 23:25:05 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void ) {

	DiamondTrap	diamond("Khylianne le diamant");
	ScavTrap	scav("Rodrigue le scav");
	FragTrap	frag("Micheline la frag");

	
	diamond.attack("Rodrigue");
	diamond.takeDamage(30);
	diamond.attack("Micheline");
	diamond.beRepaired(10);
	diamond.attack("Rodrigue");
	diamond.takeDamage(30);

	scav.attack("Khylianne");
	scav.takeDamage(30);
	scav.attack("Micheline");
	scav.beRepaired(10);
	scav.attack("Khylianne");
	
	frag.attack("Rodrigue");
	frag.takeDamage(30);
	frag.attack("Khylianne");
	frag.beRepaired(10);
	frag.attack("Rodrigue");
	frag.highFivesGuys();
	
	return (0);
}