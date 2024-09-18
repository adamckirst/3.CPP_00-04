/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:23:50 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/18 12:53:09 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/A_Animal.hpp"

A_Animal::A_Animal() : type_("")
{
	std::cout << GREEN_TEXT << "A_Animal constructor called" << RESET_FORMAT << std::endl;
}

A_Animal::A_Animal(const A_Animal &other) : type_(other.type_)
{
	std::cout << GREEN_TEXT << "A_Animal with type " << other.type_ << " copied" << RESET_FORMAT << std::endl;
}

A_Animal &A_Animal::operator=(const A_Animal &other)
{
	if (this != &other)
	{
		std::cout << GREEN_TEXT << "A_Animal with type " << other.type_ << " assigned to " << type_ << RESET_FORMAT << std::endl;
		type_ = other.type_;
	}
	return *this;
}

A_Animal::~A_Animal()
{
	std::cout << RED_TEXT << "A_Animal destructor called" << RESET_FORMAT << std::endl;
}

std::string A_Animal::getType() const
{
	return type_;
}