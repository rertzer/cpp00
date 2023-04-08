/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:56:19 by rertzer           #+#    #+#             */
/*   Updated: 2023/03/22 13:46:52 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		void		SetFirstname(std::string str);
		void		SetLastname(std::string str);
		void		SetNickname(std::string str);
		void		SetPhonenumber(std::string str);
		void		SetDarkestsecret(std::string str);
		std::string	GetFirstname(void) const;
		std::string	GetLastname(void) const;
		std::string	GetNickname(void) const;
		std::string	GetPhonenumber(void) const;
		std::string	GetDarkestsecret(void) const;
		void		PrintContact(void) const;
		int			IsValidPhonenumber(std::string input) const;

	private:
		std::string		_firstname;
		std::string		_lastname;
		std::string		_nickname;
		std::string		_phonenumber;
		std::string		_darkestsecret;
};

#endif
