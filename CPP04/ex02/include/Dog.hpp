/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:28:53 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/18 14:38:43 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "A_Animal.hpp"
#include "Brain.hpp"

class Dog : public A_Animal
{
private:
	Brain *brain_;

public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog();

	virtual void makeSound() const;
	Brain *getBrain() const;
};