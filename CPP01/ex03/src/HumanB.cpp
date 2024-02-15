#include "HumanB.hpp"


void	HumanB::attack() {std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;};
void	HumanB::setWeapon(Weapon& weapon) {weapon_ = &weapon;};