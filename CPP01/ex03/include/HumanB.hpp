#pragma once
#include "Weapon.hpp"

class HumanB
{
private:
	std::string name_;
	Weapon *weapon_;

public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon &weapon);
	HumanB(const HumanB &other);
	HumanB &operator=(const HumanB &other);
	~HumanB();

	void attack();
	void setWeapon(Weapon &weapon);
};