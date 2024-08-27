/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:21:19 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/27 18:04:53 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name_(name),
												   weapon_(weapon) {}

HumanA::HumanA(const HumanA &other) : name_(other.name_), weapon_(other.weapon_) {}

HumanA &HumanA::operator=(const HumanA &other)
{
	if (this != &other)
	{
		name_ = other.name_;
		weapon_ = other.weapon_;
	}
	return *this;
}

HumanA::~HumanA() {}

void HumanA::attack() { std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl; }

void HumanA::setWeapon(Weapon &weapon) { weapon_ = weapon; }
