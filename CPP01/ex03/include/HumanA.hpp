#pragma once
#include "Weapon.hpp"

class HumanA {
	private:
		std::string	name_;
		Weapon&	weapon_;
	
	public:
	 	HumanA(std::string name, Weapon& weapon): 
			name_(name),
			weapon_(weapon) {};
		void	attack();
		void	setWeapon(Weapon& weapon);
};