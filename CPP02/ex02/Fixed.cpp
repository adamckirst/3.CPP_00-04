/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:41:11 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/10 16:41:11by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value_(0) {}

Fixed::Fixed(const int value)
{
	value_ = value * (1 << fractional_bits_);
}

Fixed::Fixed(const float value)
{
	value_ = static_cast<int>(roundf(value * (1 << fractional_bits_)));
}

Fixed::Fixed(const Fixed &other)
{
	value_ = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		value_ = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {}

// Comparison operators

bool Fixed::operator>(const Fixed &other) const
{
	return (value_ > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (value_ < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (value_ >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (value_ <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (value_ == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (value_ != other.getRawBits());
}

// Arithmetic operators

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(value_ + other.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(value_ - other.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	int64_t tmp = static_cast<int64_t>(value_) * other.getRawBits();
	result.setRawBits(tmp >> fractional_bits_);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((value_ << fractional_bits_) / other.getRawBits());
	return (result);
}

// Increment and decrement operators

Fixed &Fixed::operator++()
{
	value_++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--()
{
	value_--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}