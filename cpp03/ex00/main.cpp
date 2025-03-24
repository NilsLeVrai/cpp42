/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:14:17 by niabraha          #+#    #+#             */
/*   Updated: 2025/03/24 17:58:13 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;

	ClapTrap Gontran;
	Gontran.setName("Gontran");

	ClapTrap Clotaire("Clotaire");
	Gontran.attack(Clotaire.getName());
	Gontran.takeDamage(5);

	Clotaire.attack(Gontran.getName());
	Clotaire.takeDamage(5);
	Clotaire.beRepaired(5);
	
	return (0);
}