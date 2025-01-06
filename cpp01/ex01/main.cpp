/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:03:13 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/06 15:21:33 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {

	int N = 5;

	Zombie *zombies = zombieHorde(N, "Jean-Zombie");
	for (int i = 0; i < N; i++)
	{
		zombies[i].announce();
	}
	delete [] zombies;
	return 0;
}