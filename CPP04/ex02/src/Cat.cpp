/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:29:44 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/18 12:52:21 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : A_Animal()
{
	type_ = "Cat";
	brain_ = new Brain();
	std::cout << GREEN_TEXT << "Cat constructor called" << RESET_FORMAT << std::endl;
}

Cat::Cat(const Cat &other) : A_Animal(other)
{
	brain_ = new Brain(*other.brain_);
	std::cout << GREEN_TEXT << other.type_ << " was copied" << RESET_FORMAT << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		std::cout << GREEN_TEXT << other.type_ << " was assigned to " << type_ << RESET_FORMAT << std::endl;
		A_Animal::operator=(other);
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}
	return *this;
}

Cat::~Cat()
{
	delete brain_;
	std::cout << RED_TEXT << "Cat destructor called" << RESET_FORMAT << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "~~ Awooooo Meow ~~" << std::endl;
}

Brain *Cat::getBrain() const
{
	return brain_;
}