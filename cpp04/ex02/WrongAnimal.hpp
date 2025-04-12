/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:41:26 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/12 16:48:24 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class WrongAAnimal
{
	public:
		WrongAAnimal();
		WrongAAnimal(std::string type);
		WrongAAnimal(const WrongAAnimal &src);
		WrongAAnimal &operator=(const WrongAAnimal &rhs);
		virtual ~WrongAAnimal();

		void makeSound() const;
		std::string getType() const;
	
	protected:
		std::string _type;
};
