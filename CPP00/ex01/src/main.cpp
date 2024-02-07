#include "../include/PhoneBook.hpp"

int	main(void) {
	PhoneBook	*phonebook = new PhoneBook();
	std::string	input;

	std::cout << "Welcome to your new PhoneBook.\nTo start, set up a password: ";
	while (!getline(std::cin, phonebook->password))
		std::cout << "Error" << std::endl;
	while (1)
	{
		std::cout << "Enter a command: (ADD, SEARCH, or EXIT)\n" << std::endl;
		getline(std::cin, input);
		if (input == "ADD")
			phonebook->add();
		else if (input == "SEARCH")
			phonebook->search();
		else if (input == "EXIT")
			break;
	}
	return 0;
}