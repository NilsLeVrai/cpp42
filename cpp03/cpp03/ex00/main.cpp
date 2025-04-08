/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:14:17 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/08 17:20:59 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap gontran("Gontran");
	ClapTrap gwendoline("Gwendoline");

	gontran.attack("Gwendoline");
	gwendoline.takeDamage(9);
	gwendoline.attack("Gontran");
	gwendoline.takeDamage(3);
	gwendoline.attack("Gontran");
	
	gwendoline.beRepaired(50);
	
	gwendoline.attack("Gontran");
	for (int i = 0; i < 10; i++)
	{
		gontran.attack("Gwendoline");
		gwendoline.takeDamage(1);
	}
	gontran.beRepaired(5);
	return (0);
}