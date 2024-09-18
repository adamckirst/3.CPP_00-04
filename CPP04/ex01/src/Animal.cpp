/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:23:50 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/17 14:49:42 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() : type_("")
{
	std::cout << GREEN_TEXT << "Animal constructor called" << RESET_FORMAT << std::endl;
}

Animal::Animal(const Animal &other) : type_(other.type_)
{
	std::cout << GREEN_TEXT << "Animal with type " << other.type_ << " copied" << RESET_FORMAT << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		std::cout << GREEN_TEXT << "Animal with type " << other.type_ << " assigned to " << type_ << RESET_FORMAT << std::endl;
		type_ = other.type_;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << RED_TEXT << "Animal destructor called" << RESET_FORMAT << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "~~ Animal sound ~~" << std::endl;
}

std::string Animal::getType() const
{
	return type_;
}