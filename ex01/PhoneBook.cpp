/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:24:00 by rertzer           #+#    #+#             */
/*   Updated: 2023/03/22 15:04:22 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_current_contact = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::AddContact(void)
{
	std::string		input = "";
	
	input = this->_GetInput("first name");
	this->_book[this->_current_contact].SetFirstname(input);

	input = this->_GetInput("last name");
	this->_book[this->_current_contact].SetLastname(input);

	input = this->_GetInput("nick name");
	this->_book[this->_current_contact].SetNickname(input);

	input = this->_GetInput("phone number");
	this->_book[this->_current_contact].SetPhonenumber(input);

	input = this->_GetInput("darkest secret");
	this->_book[this->_current_contact].SetDarkestsecret(input);

	this->_current_contact = (this->_current_contact + 1) % 8;
}

std::string	PhoneBook::_GetInput(std::string name) const
{
	std::string	input = "";

	while (input == "")
	{
		std::cout << "Enter " << name << " : ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		if (input == "")
			std::cout << "Sorry, cant't be empty" << std::endl;
		if (name == "phone number" && \
				!this->_book[this->_current_contact].IsValidPhonenumber(input))
		{
			input = "";
			std::cout << "Sorry, only digits allowed" << std::endl;
		}
	}
	return input;
}

void	PhoneBook::SearchContact(void) const
{
	unsigned int	index;

	this->_PrintTable();
	index = this->_GetIndex();
	this->_book[index].PrintContact();
}

void	PhoneBook::_PrintTable() const
{
	for (int i = 0 ; i < 8 ; i++)
	{
		//if (this->_book[i] != NULL)
			this->_PrintLine(i);
	}
}

void	PhoneBook::_PrintLine(unsigned int index) const
{
	std::cout << std::setfill (' ') << std::setw(10) << index;
	std::cout << "|";
	std::cout << std::setfill (' ') << std::setw(10) << this->_Truncate(this->_book[index].GetFirstname());
	std::cout << "|";
	std::cout << std::setfill (' ') << std::setw(10) << this->_Truncate(this->_book[index].GetLastname());
	std::cout << "|";
	std::cout << std::setfill (' ') << std::setw(10) << this->_Truncate(this->_book[index].GetNickname());
	std::cout << "|";
	std::cout << std::setfill (' ') << std::setw(10) << this->_Truncate(this->_book[index].GetPhonenumber());
	std::cout << "|";
	std::cout << std::setfill (' ') << std::setw(10) << this->_Truncate(this->_book[index].GetDarkestsecret());
	std::cout << std::endl;
}

std::string PhoneBook::_Truncate(std::string src) const
{
	std::string	dest;
	if (src.length() > 10)
	{
		dest = src.substr(0, 10);
		dest[9] = '.';
	}
	else
		dest =  src;
	return dest;
}

unsigned int	PhoneBook::_GetIndex(void) const
{
	std::string		input;
	unsigned int	index = 9;

	while (index > 7)
	{
		std::cout << "Enter an index : ";
		std::getline(std::cin, input);
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
			index = input[0] - '0';
		else
			index = 9;
		if (index > 7)
			std::cout << "\nSorry, please enter a number between 0 and 7";
		std::cout << std::endl;
	}
	return index;
}
