/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:03:04 by niabraha          #+#    #+#             */
/*   Updated: 2025/03/05 18:59:10 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	
	Fixed a;
	Fixed b;
	Fixed c( a );
	Fixed d(0.1f);
	Fixed e(6);
	Fixed f(8);
	
	a = 6;
	b = 8;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a > b = " << (a > b) << std::endl;
	std::cout << "a < b = " << (a < b) << std::endl;
	std::cout << "f >= b = " << (f >= b) << std::endl;
	std::cout << "f <= b = " << (f <= b) << std::endl;
	std::cout << "f == b = " << (f == b) << std::endl;
	std::cout << "f != b = " << (f != b) << std::endl;
	std::cout << "d - e = " << d - e << std::endl;
	std::cout << "d * e = " << d * e << std::endl;
	std::cout << "d / e = " << d / e << std::endl;

	std::cout << "++e = " << ++e << std::endl;
	std::cout << "e++ = " << e++ << std::endl;
	std::cout << "e = " << e << std::endl;

	std::cout << "++d = " << ++d << std::endl;
	std::cout << "d++ = " << d++ << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(d, e) = " << Fixed::max(d, e) << std::endl;
	std::cout << "min(d, e) = " << Fixed::min(d, e) << std::endl;
	std::cout << "max(f, b) = " << Fixed::max(f, b) << std::endl;
	std::cout << "min(f, b) = " << Fixed::min(f, b) << std::endl;
	return 0;
}