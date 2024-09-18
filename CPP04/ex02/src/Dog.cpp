/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:29:44 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/18 12:52:26 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : A_Animal()
{
	type_ = "Dog";
	brain_ = new Brain();
	std::cout << GREEN_TEXT << "Dog constructor called" << RESET_FORMAT << std::endl;
}

Dog::Dog(const Dog &other) : A_Animal(other)
{
	brain_ = new Brain(*other.brain_);
	std::cout << GREEN_TEXT << other.type_ << " was copied" << RESET_FORMAT << std::endl;
}

Dog &Dog::operator=(const Dog &other)
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

Dog::~Dog()
{
	delete brain_;
	std::cout << RED_TEXT << "Dog destructor called" << RESET_FORMAT << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "~~ Woof WOOF auau ~~" << std::endl;
}

Brain *Dog::getBrain() const
{
	return brain_;
}