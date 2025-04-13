/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:00:26 by niabraha          #+#    #+#             */
/*   Updated: 2025/04/13 23:25:31 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	this->_ideas[0] = "I am a brain";
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return *this;
}

void Brain::setIdea(int index, std::string idea)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
	else
		std::cout << "Index out of range" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->_ideas[index];
	return "Invalid index";
}