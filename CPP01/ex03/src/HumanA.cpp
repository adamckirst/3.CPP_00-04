#include "HumanA.hpp"

void	HumanA::attack() {std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;};
void	HumanA::setWeapon(Weapon& weapon) {weapon_ = weapon;};