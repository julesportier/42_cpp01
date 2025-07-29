#include "Zombie.h"

int main(void)
{
	Zombie z = Zombie("John");
	Zombie* n = newZombie("Alice");
	n->announce();
	delete n;
	return (0);
}
