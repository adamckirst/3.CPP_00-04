/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:21:18 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/26 18:21:19 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Weapon
{
private:
	std::string type_;

public:
	Weapon(std::string type);
	Weapon(const Weapon &other);
	Weapon &operator=(const Weapon &other);
	~Weapon();

	const std::string getType() const;
	void setType(std::string type);
};