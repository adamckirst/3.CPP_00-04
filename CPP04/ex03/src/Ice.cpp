/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:16:38 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/18 17:22:23 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << GREEN_TEXT << "Ice created" << RESET_FORMAT << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << GREEN_TEXT << "Ice copied" << RESET_FORMAT << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		std::cout << GREEN_TEXT << "Ice assigned" << RESET_FORMAT << std::endl;
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice()
{
	std::cout << BLUE_TEXT << "Ice destroyed" << RESET_FORMAT << std::endl;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}