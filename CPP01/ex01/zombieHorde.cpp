#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++) {
		zombies[i].setName(name);
	}
	return (zombies);
}
// Zombie* zombieHordeTest(int N, std::string name) {
// 	Zombie *zombies = new Zombie[N];
// 	std::string Number;
// 	std::ostringstream	convert;

// 	name += " ";
// 	for (int i = 0; i < N; i++) {
// 		Number = static_cast<std::ostringstream*>(&(convert << i))->str();
// 		zombies[i].setName(name + Number);
// 		convert.str("");
// 	}
// 	return (zombies);
// }