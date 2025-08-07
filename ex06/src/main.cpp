#include "Harl.h"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "You must give the log level as the unique argument\n";
		return (-1);
	}
	Harl harl;
	harl.filter(argv[1]);
	return (0);
}
