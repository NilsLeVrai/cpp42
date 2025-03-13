/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:14:17 by niabraha          #+#    #+#             */
/*   Updated: 2025/03/13 16:09:01 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

int main()
{
	ClapTrap claptrap("Claptrap");
	ClapTrap claptrap2(claptrap);
	ClapTrap claptrap3("Claptrap3");

	claptrap.attack("target");
	claptrap2.attack("target");
	claptrap3.attack("target");

	return 0;
}