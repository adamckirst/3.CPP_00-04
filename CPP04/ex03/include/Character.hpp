/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:23:06 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/18 17:26:01 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utils.hpp"
#include "AMateria.hpp"

class Character
{
private:
	std::string name_;
	AMateria *materias_[4];

public:
	Character();
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();

	std::string const &getName();
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};