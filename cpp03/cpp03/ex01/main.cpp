/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:14:17 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/07 23:35:26 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void ) {

	ClapTrap Lisette("Lisette");
	ScavTrap Zebulon("Zebulon");

	Lisette.attack("Zebulon");
	Lisette.takeDamage(3);
	Lisette.attack("Zebulon");
	Lisette.beRepaired(2);
	Lisette.attack("Zebulon");
	Zebulon.attack("Lisette");
	Zebulon.takeDamage(3);

	for (int i = 0; i < 52; i++)
	{
		Zebulon.attack("Lisette");
		Zebulon.takeDamage(3);
	}
	ScavTrap Zebulon2("Zebulon2");
	Zebulon2.attack("Lisette");
	Zebulon2.guardGate();
	
	return (0);
}