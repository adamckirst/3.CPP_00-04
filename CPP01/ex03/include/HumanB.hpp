#pragma once
#include "HumanA.hpp"

class HumanB {
	private:
		std::string	name_;
		Weapon*	weapon_;
	
	public:
	 	HumanB(std::string name): 
			name_(name) {};
	 	HumanB(std::string name, Weapon* weapon): 
			name_(name),
			weapon_(weapon) {};
		void	attack();
		void	setWeapon(Weapon& weapon);
};