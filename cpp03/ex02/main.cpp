/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:14:17 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/07 23:31:49 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void ) {

	ClapTrap Bernardeau("Bernardeau");
	ScavTrap desiree("Desiree");
	FragTrap mariechantal("Mariechantal");

	Bernardeau.attack("Desiree");
	Bernardeau.takeDamage(3);
	Bernardeau.attack("Mariechantal");
	Bernardeau.beRepaired(2);
	Bernardeau.attack("Desiree");

	desiree.attack("Bernardeau");
	desiree.takeDamage(3);
	desiree.attack("Mariechantal");
	desiree.guardGate();
	desiree.beRepaired(2);
	desiree.attack("Bernardeau");

	mariechantal.attack("Desiree");
	mariechantal.takeDamage(3);
	mariechantal.attack("Bernardeau");
	mariechantal.beRepaired(2);
	mariechantal.attack("Desiree");
	mariechantal.highFivesGuys();
	return (0);
}