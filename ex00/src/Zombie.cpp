#include "Zombie.h"
#include <iostream>

Zombie::Zombie(std::string n) : name(n) {};

Zombie::~Zombie()
{
	std::cout << this->name << " destroyed\n";
}

void Zombie::announce() const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}
