#include "Zombie.hpp"

Zombie::Zombie() {};
Zombie::Zombie(std::string name) : name_(name) {};
Zombie &Zombie::operator=(const Zombie &other)
{
  if (this != &other)
  {
    name_ = other.name_;
  }
  return *this;
};
Zombie::~Zombie() { std::cout << name_ << " died." << std::endl; };
void Zombie::announce() const
{
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
void Zombie::setName(std::string name) { name_ = name; };