/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:23:19 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/06 15:37:30 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout << "Address of the stringVAR: " << &stringVAR << std::endl;
	std::cout << "Address of the stringPTR: " << &stringPTR << std::endl;
	std::cout << "Address of the stringREF: " << &stringREF << std::endl;

	std::cout << "Value of the stringVAR: " << stringVAR << std::endl;
	std::cout << "Value of the stringPTR: " << stringPTR << std::endl;
	std::cout << "Value of the stringREF: " << stringREF << std::endl;

	return 0;
}