/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:31:29 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/12 16:47:28 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AAnimal {
	
	public:
		AAnimal();
		AAnimal(const std::string type);
		AAnimal(const AAnimal &src);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal &rhs);

		virtual void makeSound() const = 0;
		std::string getType() const;

	protected:
		std::string _type;
};
