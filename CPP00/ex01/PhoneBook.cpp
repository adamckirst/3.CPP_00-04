#include "PhoneBook.hpp"

Contact	*getContact()
{
	Contact *contact = new Contact();
	std::string input;

	std::cout << contact->lastName << std::endl;
	std::cout << "Enter first name: ";
	while (!getline(std::cin, contact->firstName))
		std::cout << "Error" << std::endl;
	std::cout << "Enter last name: ";
	while (!getline(std::cin, contact->lastName))
		std::cout << "Error" << std::endl;
	std::cout << "Enter nickname: ";
	while (!getline(std::cin, contact->nickname))
		std::cout << "Error" << std::endl;
	std::cout << "Enter phone number: ";
	while (!getline(std::cin, contact->phoneNumber))
		std::cout << "Error" << std::endl;
	std::cout << "Enter darkest secret: ";
	while (!getline(std::cin, input))
		std::cout << "Error" << std::endl;
	contact->setSecret(input);
	std::cout << "Contact added" << std::endl;
	return contact;
}

int	main(void)
{
	PhoneBook	*phonebook = new PhoneBook();
	std::string	input;

	while (1)
	{
		std::cout << "Enter a command:\nADD\nEXIT\n\n";
		getline(std::cin, input);
		if (input == "ADD")
			phonebook->add(getContact());
		// else if (input == "SEARCH")
		// 	phonebook.search();
		else if (input == "EXIT")
			break;
	}
	return 0;
}