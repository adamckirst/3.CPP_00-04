#pragma once
#include <iostream>
#include <string>

class Zombie
{
private:
  std::string name_;

public:
  Zombie();
  Zombie(std::string name);
  Zombie &operator=(const Zombie &other);
  ~Zombie();
  void announce() const;
  void setName(std::string name);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);