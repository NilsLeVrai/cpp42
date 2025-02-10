/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:46:17 by niabraha          #+#    #+#             */
/*   Updated: 2025/02/10 16:52:38 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <limits>

int main() {
	int a = 42;
	int b = 03;
	float c = 42.42f;
	float d = 0.0f;

	try {
		if (b == 0) {
			throw std::runtime_error("Division by zero (int)");
		}
		std::cout << "Resultat:" << a / b << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	try {
		if (d == 0.0f) {
			throw std::runtime_error("Division by zero (float)");
		}
		std::cout << "Resultat:" << c / d << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
