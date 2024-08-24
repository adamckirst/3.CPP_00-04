#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {}

Weapon::Weapon(const Weapon &other) : type_(other.type_) {}

Weapon &Weapon::operator=(const Weapon &other)
{
	if (this != &other)
	{
		type_ = other.type_;
	}
	return *this;
}

Weapon::~Weapon() {}

const std::string Weapon::getType() const { return type_; };
void Weapon::setType(std::string type) { type_ = type; };