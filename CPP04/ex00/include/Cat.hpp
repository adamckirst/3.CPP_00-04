/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:28:53 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/18 14:39:16 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat();

	virtual void makeSound() const;
};