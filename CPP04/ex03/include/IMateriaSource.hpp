/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:36:57 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/18 16:23:13 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utils.hpp"
#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};