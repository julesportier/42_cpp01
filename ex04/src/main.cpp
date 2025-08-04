#include "FileBuf.h"
#include <fstream>
#include <iostream>

void print_input_help()
{
	std::cout
		<< "The program takes 3 arguments\n"
		"1: file, 2: string to replace, 3: new string\n";
}

std::string convert_filename(std::string name)
{
	return (name.append(".replace"));
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
	}
	catch (int e) {
		return (e);
	}
	return (0);
}
