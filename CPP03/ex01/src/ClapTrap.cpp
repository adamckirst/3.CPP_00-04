/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:57:42 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/16 20:56:33 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : name_("unknown"), hit_points_(10), energy_points_(10), attack_dmg_(0)
{
	std::cout << GREEN_TEXT << "ClapTrap default constructor called" << RESET_FORMAT << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name_(name), hit_points_(10), energy_points_(10), attack_dmg_(0)
{
	std::cout << GREEN_TEXT << "ClapTrap " << name << " was constructed!" << RESET_FORMAT << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hit_points, int energy_points, int attack_dmg)
	: name_(name), hit_points_(hit_points),
	  energy_points_(energy_points), attack_dmg_(attack_dmg)
{
	std::cout << GREEN_TEXT << "ClapTrap " << name << " was constructed with custom attributes!" << RESET_FORMAT << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name_(other.name_), hit_points_(other.hit_points_),
											energy_points_(other.energy_points_), attack_dmg_(other.attack_dmg_)
{
	std::cout << GREEN_TEXT << "ClapTrap constructed by copying " << other.name_ << RESET_FORMAT << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
		return *this;
	std::cout << GREEN_TEXT << "ClapTrap " << other.name_ << " was assigned to " << name_ << RESET_FORMAT << std::endl;
	name_ = other.name_;
	hit_points_ = other.hit_points_;
	energy_points_ = other.energy_points_;
	attack_dmg_ = other.attack_dmg_;
	return *this;
}

ClapTrap::~ClapTrap() { std::cout << BLUE_TEXT << "ClapTrap " << name_ << " was destroyed." << RESET_FORMAT << std::endl; }

// Member functions

void ClapTrap::attack(const std::string &target)
{
	if (hit_points_ > 0 && energy_points_ > 0)
	{
		std::cout << "ClapTrap " << name_ << " attacks " << target << " for " << attack_dmg_ << " points of damage!"
				  << BLUE_TEXT << " Energy: " << energy_points_ << " > " << energy_points_ - 1 << RESET_FORMAT << std::endl;
		energy_points_ -= 1;
	}
	else if (hit_points_ == 0)
		std::cout << YELLOW_TEXT << "ClapTrap " << name_ << " is dead and cannot attack!" << RESET_FORMAT << std::endl;
	else if (energy_points_ == 0)
		std::cout << YELLOW_TEXT << "ClapTrap " << name_ << " is out of energy points!" << RESET_FORMAT << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points_ == 0)
	{
		std::cout << YELLOW_TEXT << name_ << " is already dead!" << RESET_FORMAT << std::endl;
		return;
	}
	int prev_hit_points_ = hit_points_;
	hit_points_ -= amount;
	std::cout << name_ << " takes " << amount << " points of damage!"
			  << BLUE_TEXT << " Hit points: " << prev_hit_points_ << " > " << (hit_points_ > 0 ? hit_points_ : 0) << RESET_FORMAT << std::endl;
	if (hit_points_ <= 0)
	{
		hit_points_ = 0;
		std::cout << RED_TEXT << name_ << " is dead!" << RESET_FORMAT << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points_ > 0 && energy_points_ > 0)
	{
		hit_points_ += amount;
		std::cout << name_ << " is repaired for " << amount << " hit points, to a total of" << hit_points_ << "!"
				  << BLUE_TEXT << " Energy: " << energy_points_ << " > " << energy_points_ - 1 << RESET_FORMAT << std::endl;
		energy_points_ -= 1;
	}
	else if (hit_points_ == 0)
		std::cout << YELLOW_TEXT << name_ << " is dead and cannot be repaired!" << RESET_FORMAT << std::endl;
	else if (energy_points_ == 0)
		std::cout << YELLOW_TEXT << name_ << " is out of energy points!" << RESET_FORMAT << std::endl;
}

std::string ClapTrap::getName() const { return name_; }

int ClapTrap::getHitPoints() const { return hit_points_; }

int ClapTrap::getEnergyPoints() const { return energy_points_; }

int ClapTrap::getAttackDmg() const { return attack_dmg_; }

void ClapTrap::setAttackDmg(unsigned int attack_dmg)
{
	attack_dmg_ = attack_dmg;
	std::cout << YELLOW_TEXT << name_ << " has a new attack damage of " << attack_dmg_ << "!" << RESET_FORMAT << std::endl;
}

void ClapTrap::gainEnergy(unsigned int amount)
{
	if (hit_points_ > 0)
	{
		energy_points_ += amount;
		std::cout << YELLOW_TEXT << name_ << " gained " << amount << " energy points!" << RESET_FORMAT
				  << std::endl;
	}
	else if (hit_points_ == 0)
		std::cout << YELLOW_TEXT << name_ << " is dead and cannot gain energy!" << RESET_FORMAT << std::endl;
}