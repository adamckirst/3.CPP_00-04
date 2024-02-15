#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <sstream>

class Zombie
{
	private:
		std::string name_;

	public:
	 	Zombie() {};
		Zombie(std::string name) : name_(name) {};
		~Zombie() {std::cout << name_ << " died." << std::endl;};
		void announce() const;
		void setName(std::string name) {name_ = name;};
};

Zombie* zombieHorde(int N, std::string name);