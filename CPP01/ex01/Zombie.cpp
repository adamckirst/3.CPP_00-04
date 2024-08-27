/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:20:31 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/27 16:44:49 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name_(name) {};

Zombie::~Zombie() { std::cout << name_ << " died." << std::endl; };

void Zombie::announce() const
{
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

void Zombie::setName(std::string name) { name_ = name; };