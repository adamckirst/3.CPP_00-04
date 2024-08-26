/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:20:26 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/26 18:20:27 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <sstream>

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

Zombie *zombieHorde(int N, std::string name);