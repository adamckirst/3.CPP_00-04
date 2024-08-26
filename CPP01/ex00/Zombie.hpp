/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:20:47 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/26 18:20:48 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Zombie
{
private:
  std::string name_;

public:
  Zombie();
  Zombie(std::string name);
  Zombie &operator=(const Zombie &other);
  ~Zombie();
  void announce() const;
  void setName(std::string name);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);