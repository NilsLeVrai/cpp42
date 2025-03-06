/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:46:54 by niabraha          #+#    #+#             */
/*   Updated: 2025/02/28 12:21:44 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed {

	private:
		int _value;
		static const int _fractional_bits ;
		
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed();

		Fixed(const int value);
		Fixed(const float value);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed& min(Fixed &a, Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		bool operator>(const Fixed &b) const;
		bool operator<(const Fixed &b) const;
		bool operator>=(const Fixed &b) const;
		bool operator<=(const Fixed &b) const;
		bool operator==(const Fixed &b) const;
		bool operator!=(const Fixed &b) const;
		
		Fixed operator+(const Fixed &b) const;
		Fixed operator-(const Fixed &b) const;
		Fixed operator*(const Fixed &b) const;
		Fixed operator/(const Fixed &b) const;
		
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);