#include "Fixed.hpp"

Fixed::Fixed() : value_(0) {}

Fixed::Fixed(const Fixed &other) : value_(other.value_) {}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		value_ = other.value_;
	}
	return *this;
}

Fixed::~Fixed() {}

// Methods
int Fixed::getRawBits(void) const
{
	std::bitset<sizeof(int)> bits(this->value_);
	return bits.to_ulong();
}

void Fixed::setRawBits(int const raw)
{
	this->value_ = raw;
}