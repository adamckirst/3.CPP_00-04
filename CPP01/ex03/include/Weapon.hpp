#pragma once
#include <iostream>
#include <string>

class Weapon
{
private:
	std::string type_;

public:
	Weapon(std::string type);
	Weapon(const Weapon &other);
	Weapon &operator=(const Weapon &other);
	~Weapon();

	const std::string getType() const;
	void setType(std::string type);
};