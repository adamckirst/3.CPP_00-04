#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	*phonebook = new PhoneBook();
	std::string	input;

	while (1)
	{
		std::cout << "Enter a command: (ADD, SEARCH, or EXIT)\n\n";
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