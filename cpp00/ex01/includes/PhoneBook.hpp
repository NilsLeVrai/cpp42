/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:52:33 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/07 15:01:40 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook {
	private:
	Contact _phoneDirectory[8];
	int _totalContact;
	int _tmpContact;

	public:
	PhoneBook();
	void addContact(void);
	void searchContact(void);
};