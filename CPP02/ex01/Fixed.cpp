/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:41:11 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/28 17:50:08 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	value_ = value * (1 << fractional_bits_);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	value_ = static_cast<int>(roundf(value * (1 << fractional_bits_)));
	std::cout << "Float constructor called with " << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	value_ = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		value_ = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Methods
int Fixed::getRawBits(void) const
{
	return value_;
}

void Fixed::setRawBits(int const raw)
{
	this->value_ = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(value_) / (1 << fractional_bits_));
}

int Fixed::toInt(void) const
{
	return (value_ / (1 << fractional_bits_));
}

std::ostream &Fixed::write(std::ostream &dest) const
{
	dest << this->toFloat();
	return dest;
}

std::ostream &operator<<(std::ostream &out, const Fixed &as_float)
{
	return as_float.write(out);
}