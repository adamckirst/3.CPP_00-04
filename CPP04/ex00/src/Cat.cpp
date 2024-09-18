/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:29:44 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/17 15:06:30 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
	type_ = "Cat";
	std::cout << GREEN_TEXT << "Cat constructor called" << RESET_FORMAT << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << GREEN_TEXT << other.type_ << " was copied" << RESET_FORMAT << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		std::cout << GREEN_TEXT << other.type_ << " was assigned to " << type_ << RESET_FORMAT << std::endl;
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << RED_TEXT << "Cat destructor called" << RESET_FORMAT << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "~~ Awooooo Meow ~~" << std::endl;
}