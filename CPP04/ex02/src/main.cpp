/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:22:12 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/18 14:43:21 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int main()
{
	{
		const int numAnimals = 4;
		A_Animal *animals[numAnimals];

		std::cout << BOLD_TEXT << CYAN_BG << std::endl
				  << "Creating Animals..." << RESET_FORMAT << std::endl;
		for (int i = 0; i < numAnimals; ++i)
		{
			if (i < numAnimals / 2)
			{
				std::cout << std::endl
						  << "Creating Dog on index " << i << std::endl;
				animals[i] = new Dog();
			}
			else
			{
				std::cout << std::endl
						  << "Creating Cat on index " << i << std::endl;
				animals[i] = new Cat();
			}
		}

		// Testing makeSound()
		std::cout << std::endl
				  << "Testing makeSound()..." << std::endl;
		for (int i = 0; i < numAnimals; ++i)
		{
			std::cout << std::endl
					  << "Animal on index " << i << " says:" << std::endl;
			animals[i]->makeSound();
		}

		// Deleting Animals
		std::cout << std::endl
				  << "Deleting Animals..." << std::endl;
		for (int i = 0; i < numAnimals; ++i)
		{
			std::cout << std::endl
					  << "Deleting Animal on index " << i << std::endl;
			delete animals[i];
		}
	}

	{
		std::cout << BOLD_TEXT << CYAN_BG << std::endl
				  << "Testing deep copy..." << RESET_FORMAT << std::endl;

		std::cout << "Creating Basic Dog..." << std::endl;
		Dog basic;
		std::cout << "Setting Basic's idea \"Chase the cat\"..." << std::endl;
		basic.getBrain()->setIdea(0, "Chase the cat");
		{
			std::cout << "Creating Tmp from Basic..." << std::endl;
			Dog tmp = basic; // Calls copy constructor
			std::cout << "Tmp's idea: " << tmp.getBrain()->getIdea(0) << std::endl;

			std::cout << std::endl
					  << "Setting Tmp's idea \"Sleep all day\"..." << std::endl;
			tmp.getBrain()->setIdea(0, "Sleep all day");
			std::cout << "Tmp's idea: " << tmp.getBrain()->getIdea(0) << std::endl;
			std::cout << "Basic's idea: " << basic.getBrain()->getIdea(0) << std::endl;
			std::cout << std::endl
					  << "Destroying Tmp..." << std::endl;
		}

		std::cout << std::endl
				  << "After tmp is destroyed:" << std::endl;
		std::cout << "Basic's idea: " << basic.getBrain()->getIdea(0) << std::endl;
	}

	{
		std::cout << BOLD_TEXT << CYAN_BG << std::endl
				  << "Testing assignment operator..." << RESET_FORMAT << std::endl;

		Cat cat1;
		std::cout << std::endl
				  << "Setting Cat1's idea \"Catch the mouse\"..." << std::endl;
		cat1.getBrain()->setIdea(0, "Catch the mouse");

		std::cout << std::endl
				  << "Creating Cat2 from Cat1..." << std::endl;
		Cat cat2 = cat1;
		std::cout << "Cat2's idea: " << cat2.getBrain()->getIdea(0) << std::endl;

		std::cout << std::endl
				  << "Setting Cat2's idea \"Climb the tree\"..." << std::endl;
		cat2.getBrain()->setIdea(0, "Climb the tree");

		std::cout << std::endl
				  << "New ideas:" << std::endl;
		std::cout << "Cat1's idea: " << cat1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Cat2's idea: " << cat2.getBrain()->getIdea(0) << std::endl;
	}

	return 0;
}