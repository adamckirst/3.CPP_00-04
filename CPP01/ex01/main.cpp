/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:20:34 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/27 16:45:59 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

static bool isPositiveInteger(const std::string &str)
{
	if (str.empty())
		return false;

	if (str[0] == '0' && str.length() > 1)
		return false;

	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!isdigit(str[i]))
			return false;
	}

	return true;
}

int main()
{
	std::string input;
	int N;

	std::cout << "Enter the number of zombies: " << std::endl;
	getline(std::cin, input);
	while (!isPositiveInteger(input))
	{
		std::cout << "Invalid input. Please provide a positive integer." << std::endl;
		getline(std::cin, input);
	}
	N = atoi(input.c_str());
	std::cout << "Enter the name of the zombies: " << std::endl;
	getline(std::cin, input);
	Zombie *horde = zombieHorde(N, input);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}