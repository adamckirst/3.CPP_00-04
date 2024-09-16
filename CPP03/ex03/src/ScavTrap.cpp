/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:56:28 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/16 20:32:14 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("unknown")
{
	hit_points_ = 100;
	energy_points_ = 50;
	attack_dmg_ = 20;
	std::cout << GREEN_TEXT << "ScavTrap default constructor called" << RESET_FORMAT << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hit_points_ = 100;
	energy_points_ = 50;
	attack_dmg_ = 20;
	std::cout << GREEN_TEXT << "ScavTrap " << getName() << " was constructed!" << RESET_FORMAT << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << GREEN_TEXT << "ScavTrap constructed by copying " << other.getName() << RESET_FORMAT << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << GREEN_TEXT << "ScavTrap " << getName() << " was assigned to " << other.getName() << RESET_FORMAT << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << BLUE_TEXT << "ScavTrap " << getName() << " was destroyed." << RESET_FORMAT << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (hit_points_ > 0 && energy_points_ > 0)
	{
		std::cout << "ScavTrap " << name_ << " attacks " << target << " for " << attack_dmg_ << " points of damage!"
				  << BLUE_TEXT << " Energy: " << energy_points_ << " > " << energy_points_ - 1 << RESET_FORMAT << std::endl;
		energy_points_ -= 1;
	}
	else if (hit_points_ == 0)
		std::cout << YELLOW_TEXT << "ScavTrap " << name_ << " is dead and cannot attack!" << RESET_FORMAT << std::endl;
	else if (energy_points_ == 0)
		std::cout << YELLOW_TEXT << "ScavTrap " << name_ << " is out of energy points!" << RESET_FORMAT << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << YELLOW_TEXT << "ScavTrap " << getName() << " has entered Gate keeper mode." << RESET_FORMAT << std::endl;
}