#include "../src/FileBuf.h"
#include <iostream>

void print_ok(std::string message)
{
	std::cout << "OK " << message << '\n';
}

void print_ok_exception(std::string message, std::exception& e)
{
	std::cout << "OK " << message << ": \"" << e.what() << "\"\n";
}

int print_ko(std::string message)
{
	std::cout << "KO " << message << '\n';
	return (-1);
}

int print_ko_exception(std::string message, std::exception& e)
{
	std::cout << "KO " << message << ": \"" << e.what() << "\"\n";
	return (-1);
}

void print_ok_replace(
	FileBuf& fb,
	std::string search,
	std::string replace)
{
	std::cout
		<< "OK replace(): "
		<< fb.get_ifname() << ", "
		<< search << ", " << replace << '\n'
		<< fb.get_buffer() << '\n';
}

int print_ko_replace(
	FileBuf& fb,
	std::string search,
	std::string replace)
{
	std::cout
		<< "KO replace(): "
		<< fb.get_ifname() << ", "
		<< search << ", " << replace << '\n'
		<< fb.get_buffer() << '\n';
	return (-1);
}

int print_write(std::string input, std::string output)
{
	FileBuf in(input.c_str());
	FileBuf out(output.c_str());
	std::cout
		<< "input: "
		<< in.get_ifname() << ": \n"
		<< in.get_buffer() << '\n'
		<< "output: "
		<< out.get_ifname() << ": \n"
		<< out.get_buffer() << '\n';
	return (-1);
}
