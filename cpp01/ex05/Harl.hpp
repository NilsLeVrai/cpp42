/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:03:45 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/08 16:10:03 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl {

	private:
		void _debug( void ) const;
		void _info( void ) const;
		void _warning( void ) const;
		void _error( void ) const;

	public:
		Harl( void );
		~Harl( void );
		void complain( std::string level ) const;
};
