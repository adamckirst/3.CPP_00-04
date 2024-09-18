/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:23:50 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/17 14:50:52 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal")
{
	std::cout << GREEN_TEXT << "WrongAnimal constructor called" << RESET_FORMAT << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type_(other.type_)
{
	std::cout << GREEN_TEXT << "WrongAnimal with type " << other.type_ << " copied" << RESET_FORMAT << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		std::cout << GREEN_TEXT << "WrongAnimal with type " << other.type_ << " assigned to " << type_ << RESET_FORMAT << std::endl;
		type_ = other.type_;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED_TEXT << "WrongAnimal destructor called" << RESET_FORMAT << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "~~ WrongAnimal sound ~~" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type_;
}