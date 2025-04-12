/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:40:01 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/12 17:44:40 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define TOTAL_AAnimal 4

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	// const AAnimal notPossible;
	delete j;
	delete i;
	return 0;
}