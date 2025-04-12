/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:03:27 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/12 17:42:06 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include <iostream>

class Brain {
	
	public:
		Brain();
		Brain(const Brain &src);
		~Brain();
		Brain &operator=(const Brain &rhs);
		
		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
		
	private:
		std::string _ideas[100];
};