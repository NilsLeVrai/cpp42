/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:31:11 by niabraha          #+#    #+#             */
/*   Updated: 2025/05/12 17:00:56 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include <stdexcept>

int main()
{
    try {
        Bureaucrat a("niabraha", 1); // No exception
        std::cout << a.getName() << " " << a.getGrade() << std::endl;

        Bureaucrat b("niabraha", 150); // No exception
        std::cout << b.getName() << " " << b.getGrade() << std::endl;

        Bureaucrat c("niabraha", 100); // No exception
        std::cout << c.getName() << " " << c.getGrade() << std::endl;

        Bureaucrat d("niabraha", -50);  // Exception : "Grade too high"
        std::cout << d.getName() << " " << d.getGrade() << std::endl;

        Bureaucrat e("niabraha", 2147456456);  // Exception : "Grade too high"
        std::cout << e.getName() << " " << e.getGrade() << std::endl;

        Bureaucrat f("niabraha", 0);  // Exception : "Grade too high"
        std::cout << f.getName() << " " << f.getGrade() << std::endl;

        Bureaucrat g("niabraha", 151);  // Exception : "Grade too low"
        std::cout << g.getName() << " " << g.getGrade() << std::endl;

    } catch (const std::out_of_range &e) {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    return 0;
}

