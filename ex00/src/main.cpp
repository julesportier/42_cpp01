#include "Zombie.h"

int main(void)
{
	randomChump("John");
	Zombie* n = newZombie("Alice");
	n->announce();
	delete n;
	return (0);
}
