/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:46:54 by niabraha          #+#    #+#             */
/*   Updated: 2025/03/05 17:49:29 by niabraha         ###   ########.fr       */
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

		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;

		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed &min(Fixed &lhs, Fixed &rhs);
		static const Fixed &min(const Fixed &lhs, const Fixed &rhs);
		static Fixed &max(Fixed &lhs, Fixed &rhs);
		static const Fixed &max(const Fixed &lhs, const Fixed &rhs);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);