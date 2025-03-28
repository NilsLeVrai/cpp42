/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:03:34 by niabraha          #+#    #+#             */
/*   Updated: 2025/03/09 23:05:47 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(const Point &src);
		Point &operator=(const Point &src);
		~Point();
		Point(const float x, const float y);
		Point(const Fixed &x, const Fixed &y);
		float getX() const;
		float getY() const;
		bool operator==(const Point &rhs) const;
	private:
		Fixed x_value;
		Fixed y_value;
};