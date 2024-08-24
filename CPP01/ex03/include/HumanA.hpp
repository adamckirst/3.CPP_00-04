#pragma once
#include "Weapon.hpp"

class HumanA
{
private:
	std::string name_;
	Weapon &weapon_;

public:
	HumanA();
	HumanA(std::string name, Weapon &weapon);
	HumanA(const HumanA &other);
	HumanA &operator=(const HumanA &other);
	~HumanA();

	void attack();
	void setWeapon(Weapon &weapon);
};