/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:36:48 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/06 14:58:13 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {

	Zombie *zombie1 = newZombie("Natanael");
	zombie1->announce();
	randomChump("Vulvette");
	delete zombie1;
}