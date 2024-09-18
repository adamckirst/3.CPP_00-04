/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:29:44 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/17 13:40:31 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type_ = "WrongCat";
	std::cout << GREEN_TEXT << "WrongCat constructor called" << RESET_FORMAT << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << GREEN_TEXT << "WrongCat " << other.type_ << " was copied" << RESET_FORMAT << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		std::cout << GREEN_TEXT << "WrongCat " << other.type_ << " was assigned to " << type_ << RESET_FORMAT << std::endl;
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << RED_TEXT << "WrongCat destructor called" << RESET_FORMAT << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "~~ Meow OINK OINK ~~" << std::endl;
}