/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:22:12 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/18 14:48:10 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

int main(void)
{
	{
		std::cout << BOLD_TEXT << CYAN_BG << std::endl
				  << "Testing Animal polymorphism" << RESET_FORMAT << std::endl;

		const Animal *animals[4];
		animals[0] = new Animal();
		animals[1] = new Dog();
		animals[2] = new Cat();
		animals[3] = new Dog();

		for (int i = 0; i < 4; ++i)
		{
			std::cout << std::endl
					  << CYAN_TEXT << "Animal type: " << animals[i]->getType() << RESET_FORMAT << std::endl;
			animals[i]->makeSound(); // This should call the correct makeSound() function
		}

		for (int i = 0; i < 4; ++i)
			delete animals[i];
	}

	{
		std::cout << BOLD_TEXT << CYAN_BG << std::endl
				  << "Testing WrongAnimal polymorphism" << RESET_FORMAT << std::endl;

		const WrongAnimal *wrongAnimals[2];
		wrongAnimals[0] = new WrongAnimal();
		wrongAnimals[1] = new WrongCat();

		for (int i = 0; i < 2; ++i)
		{
			std::cout << std::endl
					  << CYAN_TEXT << "WrongAnimal type: " << wrongAnimals[i]->getType() << RESET_FORMAT << std::endl;
			std::cout << "Attempting to call makeSound():" << std::endl;
			wrongAnimals[i]->makeSound(); // This will call WrongAnimal::makeSound()

			// Add casting and call WrongCat::makeSound() if possible
			const WrongCat *wrongCatPtr = dynamic_cast<const WrongCat *>(wrongAnimals[i]);
			if (wrongCatPtr)
			{
				std::cout << "Casting succeeded, calling WrongCat::makeSound():" << std::endl;
				wrongCatPtr->makeSound(); // Calls WrongCat::makeSound()
			}
			else
				std::cout << "Casting failed, cannot call WrongCat::makeSound()" << std::endl;
		}

		for (int i = 0; i < 2; ++i)
			delete wrongAnimals[i];
	}

	{
		std::cout << BOLD_TEXT << CYAN_BG << std::endl
				  << "Testing Copy Constructors and Assignment Operators" << RESET_FORMAT << std::endl;

		std::cout << std::endl
				  << "Creating Original Cat..." << std::endl;
		Cat originalCat;
		std::cout << "copying Original Cat..." << std::endl;
		Cat copyCat(originalCat);
		std::cout << "assigning Original Cat..." << std::endl;
		Cat assignedCat;
		assignedCat = originalCat;

		std::cout << std::endl
				  << "Creating Original Dog..." << std::endl;
		Dog originalDog;
		std::cout << "copying Original Dog..." << std::endl;
		Dog copyDog(originalDog);
		std::cout << "assigning Original Dog..." << std::endl;
		Dog assignedDog;
		assignedDog = originalDog;
	}

	return 0;
}