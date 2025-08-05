#include "FileBuf.h"
#include <iostream>

static void print_input_help()
{
	std::cout
		<< "The program takes 3 arguments\n"
		"1: file, 2: string to replace, 3: new string\n";
}

int main(int argc, char *argv[])
{
	if (argc != 4) {
		print_input_help();
		return (0);
	}
	try {
		FileBuf fb(argv[1]);
		fb.replace(argv[2], argv[3]);
		fb.write_disk();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return (-1);
	}
	return (0);
}
