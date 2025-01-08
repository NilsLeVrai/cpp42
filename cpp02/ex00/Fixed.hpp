/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:22:59 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/08 18:11:31 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {

	private:
		int _value;
		//static const int fracBits = 8;
	
	public:
		Fixed( void ) : _value(0);
		Fixed(const Fixed& other) : _value(other.value);
		Fixed& operator=(const Fixed& other);
		~Fixed( void );

		int getRawBits( void ) const;
		void setRawBits( int const raw);
};