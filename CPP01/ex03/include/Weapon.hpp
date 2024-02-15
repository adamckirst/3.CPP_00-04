#pragma once
#include <iostream>
#include <string>

class Weapon {
	private:
		std::string type_;

	public:
		Weapon(std::string type):
			type_(type) {};
		const std::string&	getType() const;
		void	setType(std::string type);
};