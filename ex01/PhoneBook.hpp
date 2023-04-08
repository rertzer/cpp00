/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:34:13 by rertzer           #+#    #+#             */
/*   Updated: 2023/03/22 13:49:30 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cctype>
#include "Contact.hpp"

class	PhoneBook
{
	public:
						PhoneBook(void);
						~PhoneBook(void);

		void			AddContact(void);
		void			SearchContact(void) const;

	private:
		int				_current_contact;
		Contact			_book[8];

		std::string		_GetInput(std::string name) const;
		std::string		_Truncate(std::string src) const;
		unsigned int	_GetIndex(void) const;
		void			_PrintTable(void) const;
		void			_PrintLine(unsigned int index) const;
};

#endif
