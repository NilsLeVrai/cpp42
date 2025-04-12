/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:40:01 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/12 17:27:43 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define TOTAL_ANIMAL 4

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		std::cout << std::endl;
		Animal	*animals[TOTAL_ANIMAL];
		int n = -1;
		while (++n < TOTAL_ANIMAL) {
			if (n % 2) {
				animals[n] = new Dog();
				((Dog *)animals[n])->setBrainIdeas("Biscrok");
				((Dog *)animals[n])->setBrainIdea(0, "Pipi");
				((Dog *)animals[n])->setBrainIdea(99, "Caca");
				// ((Dog *)animals[n])->printIdeas();
			}
			else {
				animals[n] = new Cat();
				((Cat *)animals[n])->setBrainIdeas("Juger");
				((Cat *)animals[n])->setBrainIdea(0, "Poisson");
				((Cat *)animals[n])->setBrainIdea(99, "Dodo");
				// ((Cat *)animals[n])->printIdeas();
			}
		}
		n = -1;
		while (++n < TOTAL_ANIMAL)
			std::cout << animals[n]->getType() << std::endl;
		n = -1;
		while (++n < TOTAL_ANIMAL)
			delete animals[n];
	}
	{
		std::cout << std::endl;
		Cat	*kitty = new Cat();
		kitty->setBrainIdeas("Jugement");
		kitty->setBrainIdea(0, "Poisson");
		kitty->setBrainIdea(99, "Dodo");
		Cat	*mreow = new Cat();
		mreow->setBrainIdeas("Caca");
		std::cout << "Mreow brain before copy : ";
		mreow->printIdeas();
		*mreow = *kitty;
		delete kitty;
		std::cout << "Mreow brain after copy : ";
		mreow->printIdeas();
		delete mreow;
	}
	return 0;
}