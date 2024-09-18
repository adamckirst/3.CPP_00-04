/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:29:44 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/17 14:21:01 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
	type_ = "Dog";
	std::cout << GREEN_TEXT << "Dog constructor called" << RESET_FORMAT << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << GREEN_TEXT << "Dog " << other.type_ << " was copied" << RESET_FORMAT << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		std::cout << GREEN_TEXT << "Dog " << other.type_ << " was assigned to " << type_ << RESET_FORMAT << std::endl;
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << RED_TEXT << "Dog destructor called" << RESET_FORMAT << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "~~ Woof WOOF auau ~~" << std::endl;
}