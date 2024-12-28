/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:56:52 by niabraha          #+#    #+#             */
/*   Updated: 2024/12/19 16:14:44 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Contact.hpp"

Contact::Contact( void ) {
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

void Contact::displaySpecificContact(int i) {

	std::cout << std::setw(10) << i << "|";
	if (this->_firstName.size() > 10) {
		std::cout << this->_firstName.substr(0, 9) << ".";
		std::cout << "|";
	}
	else {
		std::cout << std::setw(10) << this->_firstName;
		std::cout << "|";
	}
	if (this->_lastName.size() > 10) {
		std::cout << this->_lastName.substr(0, 9) << ".";
		std::cout << "|";
	}
	else {
		std::cout << std::setw(10) << this->_lastName;
		std::cout << "|";
	}
	if (this->_nickname.size() > 10) {
		std::cout << this->_nickname.substr(0, 9) << ".";
		std::cout << "|";
	}
	else {
		std::cout << std::setw(10) << this->_nickname;
		std::cout << "|";
	}
	std::cout << std::endl << std::endl;
}

void Contact::displayAllContact() {
	std::cout << std::left;
	std::cout << std::setw(16) << "First name: " << this->_firstName << std::endl;
	std::cout << std::setw(16) << "Last name: " << this->_lastName << std::endl;
	std::cout << std::setw(16) << "Nickname: " << this->_nickname << std::endl;
	std::cout << std::setw(16) << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << std::setw(16) << "Darkest secret: " << this->_darkestSecret << std::endl;
}

void Contact::proceed() {

	std::string param;

	/* First name */
	
	while (true) {
	std::cout << "Enter first name: ";
	std::getline(std::cin, this->_firstName);

	if (std::cin.eof()) {
		std::cout << "End of input." << std::endl;
		exit(0);
	}

	if (this->_firstName.empty()) {
		std::cout << "First name cannot be empty. Please try again." << std::endl;
		continue;
	}

	bool hasDigit = false;
	for (size_t i = 0; i < this->_firstName.size(); i++) {
		if (std::isdigit(this->_firstName[i])) {
			hasDigit = true;
			break;
		}
	}

	if (hasDigit) {
		std::cout << "First name cannot contain digits. Please try again." << std::endl;
		this->_firstName.clear();
		continue;
	}

	break;
	}

	/* Last name */
	while (true) {
	std::cout << "Enter last name: ";
	std::getline(std::cin, this->_lastName);

	if (std::cin.eof()) {
		std::cout << "End of input." << std::endl;
		exit(0);
	}

	if (this->_lastName.empty()) {
		std::cout << "Last name cannot be empty. Please try again." << std::endl;
		continue;
	}

	bool hasDigit = false;
	for (size_t i = 0; i < this->_lastName.size(); i++) {
		if (std::isdigit(this->_lastName[i])) {
			hasDigit = true;
			break;
		}
	}

	if (hasDigit) {
		std::cout << "Last name cannot contain digits. Please try again." << std::endl;
		this->_lastName.clear();
		continue;
	}

	break;
	}
	
	/* Nickname */
	while (true) {
	std::cout << "Enter nickname: ";
	std::getline(std::cin, this->_nickname);
	
	if (std::cin.eof()) {
		std::cout << "End of input." << std::endl;
		exit(0);
	}

	if (this->_nickname.empty()) {
		std::cout << "Nickname cannot be empty. Please try again." << std::endl;
		continue;
	}
	break;
	}

	/* Phone number */
	while (true) {
	std::cout << "Enter phone number: ";
	std::getline(std::cin, this->_phoneNumber);
	
	if (std::cin.eof()) {
		std::cout << "End of input." << std::endl;
		exit(0);
	}

	if (this->_phoneNumber.empty()) {
		std::cout << "Phone number cannot be empty. Please try again." << std::endl;
		continue;
	}

	bool hasDigit = true;

	for (size_t i = 0; i < this->_phoneNumber.size(); i++) {
		if (!std::isdigit(this->_phoneNumber[i])) {
			hasDigit = false;
			break;
		}
	}

	if (!hasDigit) {
		std::cout << "Phone number cannot contain letters. Please try again." << std::endl;
		this->_phoneNumber.clear();
		continue;
	}

	break;
	}

	/* Darkest secret */

	while (true) {
	std::cout << "Enter darkest secret: "; 
	std::getline(std::cin, this->_darkestSecret);

	if (std::cin.eof()) {
		std::cout << "End of input." << std::endl;
		exit(0);
	}

	if (this->_darkestSecret.empty()) {
		std::cout << "Darkest secret cannot be empty. Please try again." << std::endl;
		continue;
	}

	break;
	}
	
}