/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:02:18 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/16 18:05:52 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {

	private:
		int _value;
		static const int _fracBits;

	public:
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);
		Fixed &operator=(Fixed const & rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};