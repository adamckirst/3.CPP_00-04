/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:20:46 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/26 18:20:47 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {};
Zombie::Zombie(std::string name) : name_(name) {};
Zombie &Zombie::operator=(const Zombie &other)
{
  if (this != &other)
  {
    name_ = other.name_;
  }
  return *this;
};
Zombie::~Zombie() { std::cout << name_ << " died." << std::endl; };
void Zombie::announce() const
{
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
void Zombie::setName(std::string name) { name_ = name; };