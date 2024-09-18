/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:20:12 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/18 16:35:24 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utils.hpp"
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type_;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	~AMateria();

	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};