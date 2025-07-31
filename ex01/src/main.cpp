#include "Zombie.h"

int main(void)
{
	int N = 4;
	Zombie* horde = zombieHorde(N, "Alice");
	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}
	delete[] horde;

	N = 2;
	horde = zombieHorde(N, "Roger");
	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
