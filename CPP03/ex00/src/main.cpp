/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:57:43 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/13 13:34:18 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main(void)
{
	ClapTrap jon_snow("Jon Snow");
	ClapTrap white_walker("White Walker", 20, 10, 6);
	ClapTrap white_walker2(white_walker);
	ClapTrap white_walker3;
	white_walker3 = white_walker2;

	std::cout << BOLD_TEXT << CYAN_TEXT << "Jon Snow lost his sword!" << RESET_FORMAT << std::endl;
	for (int i = 0; i < 11; i++)
		jon_snow.attack(white_walker.getName());

	white_walker.attack(jon_snow.getName());
	jon_snow.takeDamage(white_walker.getAttackDmg());
	std::cout << std::endl
			  << BOLD_TEXT << CYAN_TEXT << "Jon Snow used a potion to recover energy!" << RESET_FORMAT << std::endl;
	jon_snow.gainEnergy(5);

	std::cout << std::endl
			  << BOLD_TEXT << CYAN_TEXT << "Ghost joined the fight!" << RESET_FORMAT << std::endl;
	ClapTrap wolf("Ghost", 30, 15, 15);
	wolf.attack(white_walker.getName());
	white_walker.takeDamage(wolf.getAttackDmg());
	std::cout << std::endl
			  << BOLD_TEXT << CYAN_TEXT << "Jon Snow reached the dragonglass sword!" << RESET_FORMAT << std::endl;
	jon_snow.setAttackDmg(20);
	jon_snow.attack(white_walker.getName());
	white_walker.takeDamage(jon_snow.getAttackDmg());
	white_walker2.attack(wolf.getName());
	wolf.takeDamage(white_walker2.getAttackDmg());
	white_walker3.attack(wolf.getName());
	wolf.takeDamage(white_walker3.getAttackDmg());

	jon_snow.attack(white_walker2.getName());
	white_walker2.takeDamage(jon_snow.getAttackDmg());

	jon_snow.attack(white_walker3.getName());
	white_walker3.takeDamage(jon_snow.getAttackDmg());

	std::cout << std::endl
			  << BOLD_TEXT << CYAN_TEXT << "The battle is over!" << RESET_FORMAT << std::endl;
	return 0;
}