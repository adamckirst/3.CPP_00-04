/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:55:32 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/26 18:39:34 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	Harl harl;
	return (0);
}