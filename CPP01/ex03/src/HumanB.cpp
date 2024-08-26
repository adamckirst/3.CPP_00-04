/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:21:21 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/26 18:21:22 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name) {}

HumanB::HumanB(std::string name, Weapon &weapon) : name_(name),
												   weapon_(&weapon) {}

HumanB::HumanB(const HumanB &other) : name_(other.name_), weapon_(other.weapon_) {}

HumanB &HumanB::operator=(const HumanB &other)
{
	if (this != &other)
	{
		name_ = other.name_;
		weapon_ = other.weapon_;
	}
	return *this;
}

HumanB::~HumanB() {}

void HumanB::attack() { std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl; }

void HumanB::setWeapon(Weapon &weapon) { weapon_ = &weapon; }