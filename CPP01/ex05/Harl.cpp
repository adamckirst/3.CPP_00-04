/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:55:38 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/27 16:55:38 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "Uh, Rick, I really think that portal gun is, like, the coolest thing ever. \
	I mean, I love watching you tinker with it. It's so, uh, fascinating!"
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "Geez, Rick, every time we go on these crazy adventures, \
	I end up covered in some alien goo or another. It’s like, can’t we have just \
	one normal day without almost dying?"
			  << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I don’t know, Rick... I mean, messing with the time stream seems like a \
	really bad idea. What if we end up, like, creating a paradox or something?"
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "Oh man, Rick, this is bad! Really bad! We’re totally screwed! \
	We gotta get out of here before everything blows up, or—or we get vaporized, or something !"
			  << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}

	std::cout << RED_TEXT << "Invalid level." << RESET_FORMAT << std::endl;
}