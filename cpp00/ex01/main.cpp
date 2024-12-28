/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:33:46 by niabraha          #+#    #+#             */
/*   Updated: 2024/12/19 14:27:37 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PhoneBook.hpp"

int main() {
    PhoneBook repertory;
    std::string param;
    
    while (1) {
		std::cout << "\033[1;32mEnter a command: ADD, SEARCH or EXIT\033[0m" << std::endl;
		param.clear();

        if (!(std::getline(std::cin, param))) {
            std::cout << "End of input." << std::endl;
            break;
        }
        if (param == "ADD") {
            repertory.addContact();
        } else if (param == "SEARCH") {
            repertory.searchContact();
        } else if (param == "EXIT") {
            break;
        } else {
			std::cout << "\033[1;31mInvalid command. Either type ADD, SEARCH or EXIT\033[0m" << std::endl;
        }
		
    }
}
