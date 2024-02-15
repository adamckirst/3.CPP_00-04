#include "Zombie.hpp"

int main() {
	std::string input = "a";
	int N;
	std::regex pattern("^\\d+$");

	std::cout << "Enter the number of zombies: " << std::endl;
	getline(std::cin, input);
	while (!std::regex_match(input, pattern))
	{
		std::cout << "Invalid input. Please provide a positive integer." << std::endl;
		getline(std::cin, input);
	}
	N = std::atoi(input.c_str());
	Zombie* zombie= zombieHorde(N, "Zombie");
	for (int i = 0; i < N; i++)
		zombie[i].announce();
	delete[] zombie;
	return (0);
}