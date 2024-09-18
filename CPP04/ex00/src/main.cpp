/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:22:12 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/17 15:04:27 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

int main(void)
{
	{
		std::cout << std::endl
				  << BOLD_TEXT << CYAN_TEXT << "Testing Animal polymorphism" << RESET_FORMAT << std::endl;

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
		{
			delete animals[i];
		}
	}

	{
		std::cout << std::endl
				  << BOLD_TEXT << CYAN_TEXT << "Testing WrongAnimal polymorphism" << RESET_FORMAT << std::endl;

		const WrongAnimal *wrongAnimals[2];
		wrongAnimals[0] = new WrongAnimal();
		wrongAnimals[1] = new WrongCat();

		for (int i = 0; i < 2; ++i)
		{
			std::cout << std::endl
					  << CYAN_TEXT << "WrongAnimal type: " << wrongAnimals[i]->getType() << RESET_FORMAT << std::endl;
			wrongAnimals[i]->makeSound(); // This should not call WrongCat's makeSound()
		}

		for (int i = 0; i < 2; ++i)
		{
			delete wrongAnimals[i];
		}
	}

	{
		std::cout << std::endl
				  << BOLD_TEXT << CYAN_TEXT << "Testing Copy Constructors and Assignment Operators" << RESET_FORMAT << std::endl;

		Cat originalCat;
		Cat copyCat(originalCat); // Copy constructor
		Cat assignedCat;
		assignedCat = originalCat; // Assignment operator

		Dog originalDog;
		Dog copyDog(originalDog); // Copy constructor
		Dog assignedDog;
		assignedDog = originalDog; // Assignment operator
	}

	{
		std::cout << std::endl
				  << BOLD_TEXT << CYAN_TEXT << "Testing Destructors Order" << RESET_FORMAT << std::endl;

		Animal *animal = new Cat();
		delete animal; // Should call Cat's destructor and then Animal's destructor

		WrongAnimal *wrongAnimal = new WrongCat();
		delete wrongAnimal; // Should call WrongAnimal's destructor (WrongCat's destructor may not be called correctly)
	}

	return 0;
}