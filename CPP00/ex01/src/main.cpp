#include "../include/PhoneBook.hpp"
#include "../include/helpers.hpp"

void sig_handler(int signum)
{
	if (signum == SIGINT)
		exit(signum);
}

void ft_getline(std::string &input)
{
	signal(SIGINT, sig_handler);
	getline(std::cin, input);

	if (std::cin.eof())
	{
		std::cerr << std::endl
				  << BOLD_TEXT << RED_TEXT << "ERROR: closed input stream." << std::endl;
		exit(1);
	}
}

int main(void)
{
	PhoneBook phonebook;
	std::string input;

	std::cout << "Welcome to your new PhoneBook.\nTo start, set up a password for secrets or leave empty: ";
	ft_getline(input);
	while (!phonebook.setPassword(input))
	{
		std::cout << "Invalid password. Please try again: ";
		ft_getline(input);
	}
	while (1)
	{
		std::cout << "Enter a command: (ADD, SEARCH, or EXIT)\n"
				  << std::endl;
		ft_getline(input);
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break;
	}
	return 0;
}