#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name_(name),
												   weapon_(weapon) {}

HumanA::HumanA(const HumanA &other) : name_(other.name_), weapon_(other.weapon_) {}

HumanA &HumanA::operator=(const HumanA &other)
{
	if (this != &other)
	{
		name_ = other.name_;
		weapon_ = other.weapon_;
	}
	return *this;
}

HumanA::~HumanA() {}

void HumanA::attack() { std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl; }

void HumanA::setWeapon(Weapon &weapon) { weapon_ = weapon; }
