#include "Zombie.h"
#include <string>

Zombie* newZombie(std::string name)
{
	Zombie* z = new Zombie;
	z->set_name(name);
	return (z);
}
