/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:21:16 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/27 16:48:28 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanB
{
private:
	std::string name_;
	Weapon *weapon_;

public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon &weapon);
	HumanB(const HumanB &other);
	HumanB &operator=(const HumanB &other);
	~HumanB();

	void attack();
	void setWeapon(Weapon &weapon);
};