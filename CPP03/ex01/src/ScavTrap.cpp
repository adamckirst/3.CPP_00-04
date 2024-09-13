/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:56:28 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/13 13:23:19 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("unknown", 100, 50, 20)
{
	std::cout << GREEN_TEXT << "ScavTrap default constructor called" << RESET_FORMAT << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << GREEN_TEXT << "ScavTrap " << name << " was constructed!" << RESET_FORMAT << std::endl;
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

void ScavTrap::guardGate()
{
	std::cout << YELLOW_TEXT << "ScavTrap " << getName() << " has entered Gate keeper mode." << RESET_FORMAT << std::endl;
}