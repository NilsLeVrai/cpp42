/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:39:12 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/12 17:45:22 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"
#include <iostream>

class WrongDog : public WrongAAnimal
{
	public:
		WrongDog();
		WrongDog(const WrongDog &src);
		WrongDog &operator=(const WrongDog &copy);
		~WrongDog();

		void makeSound() const;
};