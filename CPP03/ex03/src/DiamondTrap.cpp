/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:58:16 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/16 21:03:18 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("unknown_clap_name"), ScavTrap(), FragTrap(), name_("unknown")
{
	hit_points_ = FragTrap::hit_points_;
	energy_points_ = ScavTrap::energy_points_;
	attack_dmg_ = FragTrap::attack_dmg_;
	std::cout << GREEN_TEXT << "DiamondTrap default constructor called" << RESET_FORMAT << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name_(name)
{
	hit_points_ = FragTrap::hit_points_;
	energy_points_ = ScavTrap::energy_points_;
	attack_dmg_ = FragTrap::attack_dmg_;
	std::cout << GREEN_TEXT << "DiamondTrap " << name_ << " was constructed!" << RESET_FORMAT << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << GREEN_TEXT << "DiamondTrap constructed by copying " << other.name_ << RESET_FORMAT << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << GREEN_TEXT << "DiamondTrap " << other.name_ << " was assigned to " << name_ << RESET_FORMAT << std::endl;
		name_ = other.name_;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BLUE_TEXT << "DiamondTrap " << name_ << " was destroyed." << RESET_FORMAT << std::endl;
}

std::string DiamondTrap::getName() const
{
	return name_;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << YELLOW_TEXT << "DiamondTrap name: " << name_ << std::endl
			  << "ClapTrap name: " << ClapTrap::name_ << RESET_FORMAT << std::endl;
}