#pragma once
#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name_;

	public:
	 	Zombie() {};
		Zombie(std::string name) : name_(name) {};
		~Zombie() {std::cout << name_ << " died." << std::endl;};
		void announce() const {std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;};
		void setName(std::string name) {name_ = name;};
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);