#include <string>
#include "Zombie.h"

void randomChump(std::string name)
{
	Zombie z;
	z.set_name(name);
	z.announce();
}
