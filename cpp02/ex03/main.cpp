/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:03:04 by niabraha          #+#    #+#             */
/*   Updated: 2025/03/09 23:08:08 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	Point a(2, 6);
	Point b(-2, 3);
	Point c(0, 4);
	Point d(0.6f ,4.7f);
	Point e(-0.67f , 3.9f);
	Point f(-1.5f , 3.5f);
	Point g(-2, 3);

	std::cout << bsp(a, b, c, d) << std::endl;
	std::cout << bsp(a, b, c, e) << std::endl;
	std::cout << bsp(a, b, c, f) << std::endl;
	std::cout << bsp(a, b, c, g) << std::endl;
}