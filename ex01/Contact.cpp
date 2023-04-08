/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:11:25 by rertzer           #+#    #+#             */
/*   Updated: 2023/03/22 14:11:29 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::SetFirstname(std::string str)
{
	this->_firstname = str;	
}

void	Contact::SetLastname(std::string str)
{
	this->_lastname = str;	
}

void	Contact::SetNickname(std::string str)
{
	this->_nickname = str;	
}

void	Contact::SetPhonenumber(std::string str)
{
	if (this->IsValidPhonenumber(str))
		this->_phonenumber = str;	
}

void	Contact::SetDarkestsecret(std::string str)
{
	this->_darkestsecret = str;	
}

std::string	Contact::GetFirstname(void) const
{
	return this->_firstname;
}

std::string	Contact::GetLastname(void) const
{
	return this->_lastname;
}

std::string	Contact::GetNickname(void) const
{
	return this->_nickname;
}

std::string	Contact::GetPhonenumber(void) const
{
	return this->_phonenumber;
}
std::string	Contact::GetDarkestsecret(void) const
{
	return this->_darkestsecret;
}
void	Contact::PrintContact(void) const
{
	std::cout << "firstname : " << this->_firstname << std::endl;
	std::cout << "lastname : " << this->_lastname << std::endl;
	std::cout << "nickname : " << this->_nickname << std::endl;
	std::cout << "phonenumber : " << this->_phonenumber << std::endl;
	std::cout << "darkestsecret : " << this->_darkestsecret << std::endl;
}

int	Contact::IsValidPhonenumber(std::string input) const
{
	for (unsigned int i = 0 ; i < input.length() ; i++)
	{
		if (!std::isdigit(input[i]))
			return 0;
	}
	return 1;
}
