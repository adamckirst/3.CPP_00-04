/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:21:24 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/26 18:21:25 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {}

Weapon::Weapon(const Weapon &other) : type_(other.type_) {}

Weapon &Weapon::operator=(const Weapon &other)
{
	if (this != &other)
	{
		type_ = other.type_;
	}
	return *this;
}

Weapon::~Weapon() {}

const std::string Weapon::getType() const { return type_; };
void Weapon::setType(std::string type) { type_ = type; };