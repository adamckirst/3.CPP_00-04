/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:38:59 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/17 19:56:04 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("unknown")
{
	hit_points_ = 100;
	energy_points_ = 100;
	attack_dmg_ = 30;
	std::cout << GREEN_TEXT << "FragTrap default constructor called" << RESET_FORMAT << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hit_points_ = 100;
	energy_points_ = 100;
	attack_dmg_ = 30;
	std::cout << GREEN_TEXT << "FragTrap " << name_ << " was constructed!" << RESET_FORMAT << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << GREEN_TEXT << "FragTrap constructed by copying " << other.getName() << RESET_FORMAT << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << GREEN_TEXT << "FragTrap " << getName() << " was assigned to " << other.getName() << RESET_FORMAT << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << BLUE_TEXT << "FragTrap " << getName() << " was destroyed." << RESET_FORMAT << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << YELLOW_TEXT << "FragTrap " << getName() << " requests a high five!" << RESET_FORMAT << std::endl;
}