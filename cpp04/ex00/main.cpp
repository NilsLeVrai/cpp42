/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:40:01 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/05 17:29:26 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *animals[4];
	
	std::cout << "\033[1;34mConstructors called\033[0m" << std::endl;

	std::cout << "\033[0;34m" << std::endl;
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[1;35mDog is in purple\033[0m" << std::endl;
	std::cout << "\033[1;33mCat is in yellow\033[0m" << std::endl;
	std::cout << "\033[1;32mAnimal is in green\033[0m" << std::endl << std::endl;


	for (int i = 0; i < 4; i++)
	{
		if (animals[i]->getType() == "Dog")
			std::cout << "\033[1;35m";
		else if (animals[i]->getType() == "Cat")
			std::cout << "\033[1;33m";
		else
			std::cout << "\033[1;32m";
		std::cout << "I'm an animal and i'm a " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
		std::cout << "\033[0m" << std::endl;
	}
	std::cout << "\033[1;31m" << "Everything has to be destroyed." << "\033[0m" << std::endl << std::endl;
	std::cout << "\033[0;31m";
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
	}
	std::cout << "\033[0m" << std::endl;



	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " le chieng " << std::endl;
	std::cout << i->getType() << " le cha " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	
	return 0;
}