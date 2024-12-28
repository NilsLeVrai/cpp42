/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:08:33 by niabraha          #+#    #+#             */
/*   Updated: 2024/12/24 15:28:04 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook() {
	this->_totalContact = 0;
}

void PhoneBook::addContact(void) {

	if (this->_totalContact < 8)
	{
		this->_phoneDirectory[this->_totalContact].proceed();
		this->_totalContact++;
		this->_tmpContact = this->_totalContact;
	}
	else
	{
		std::cout << "\033[1;32mPhonebook is full. Replacing the oldest contact with this new one.\033[0m" << std::endl;
		this->_phoneDirectory[this->_tmpContact % 8].proceed();
		this->_tmpContact += 1;
	}
}

void PhoneBook::searchContact(void) {
	
	int 		index;
	std::string param;

	if (this->_totalContact == 0) {
		std::cout << "\033[1;35mPhonebook is empty.\033[0m" << std::endl;
		return;
	}
	std::cout << "\033[1;33mHere is your repertory." << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout <<  "|      Displaying all your contacts        |" << std::endl;
	std::cout << "|    index|first name| last name|nickname  |" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "\033[0m" << std::endl;
	
	for (int i = 0; i < this->_totalContact; i++) {
		this->_phoneDirectory[i].displaySpecificContact(i);
	}
	while (true) {
		std::cout << "\033[1;34mEnter the index of the contact you want to search:\033[0m" << std::endl;
		if (!(std::getline(std::cin, param))) {
			std::cout << "Signal received." << std::endl;
			return;
		}
		std::stringstream ss(param);
		if (!(ss >> index)) {
			std::cout << "\033[1;31mInvalid index. Please enter a valid number.\033[0m" << std::endl;
			continue;
		}
		if (index >= 0 && index < this->_totalContact) {
			break;
		}
		std::cout << "\033[1;31mInvalid index. Please enter a valid index.\033[0m" << std::endl;
	}
	if (index < this->_totalContact) {
		std::cout << "\033[1;33mDisplaying your specific contact's informations.\033[0m" << std::endl;
		this->_phoneDirectory[index].displayAllContact();
	}
}