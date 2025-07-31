#include "Zombie.h"
#include <iostream>

Zombie::Zombie() {};

Zombie::~Zombie()
{
	std::cout << this->name << " destroyed\n";
}

void Zombie::announce() const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}
