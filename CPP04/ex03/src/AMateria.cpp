/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:39:46 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/18 17:22:38 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

AMateria::AMateria()
{
	std::cout << GREEN_TEXT << "Materia created" << RESET_FORMAT << std::endl;
}

AMateria::AMateria(std::string const &type) : type_(type)
{
	std::cout << GREEN_TEXT << type_ << " materia created" << RESET_FORMAT << std::endl;
}

AMateria::AMateria(const AMateria &other) : type_(other.type_) {}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		type_ = other.type_;
	}
	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
	return type_;
}