/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:21:15 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/26 18:21:16 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanA
{
private:
	std::string name_;
	Weapon &weapon_;

public:
	HumanA();
	HumanA(std::string name, Weapon &weapon);
	HumanA(const HumanA &other);
	HumanA &operator=(const HumanA &other);
	~HumanA();

	void attack();
	void setWeapon(Weapon &weapon);
};