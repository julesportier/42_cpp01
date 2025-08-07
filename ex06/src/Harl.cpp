#include "Harl.h"
#include <iostream>

/******************
 * PUBLIC METHODS *
 * ***************/
static harl_fn at(std::string level, harl_map const* map)
{
	for (int i = 0; i < 4; ++i) {
		if (level == map[i].level)
			return (map[i].f_ptr);
	}
	std::cerr << "level \"" << level << "\" not found\n";
	return (NULL);
}

void Harl::complain(std::string level) const
{
	struct harl_map const map[4] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};
	harl_fn level_fn = at(level, map);
	if (level_fn)
		(this->*level_fn)();
}

static int find(std::string str, std::string const* lookup, int size)
{
	for (int i = 0; i < size; ++i) {
		if (lookup[i] == str) {
			return (i);
		}
	}
	return (-1);
}

static void print_level(std::string level)
{
	std::cout << "[ " << level << " ]\n";
}

void Harl::filter(std::string level) const
{
	std::string const lookup[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = find(level, lookup, 4);
	switch(index) {
		case 0:
			print_level("DEBUG");
			this->complain("DEBUG");
		case 1:
			print_level("INFO");
			this->complain("INFO");
		case 2:
			print_level("WARNING");
			this->complain("WARNING");
		case 3:
			print_level("ERROR");
			this->complain("ERROR");
			break;
		default:
			print_level("Probably complaining about insignifiant problems");
	};
}

/*******************
 * PRIVATE METHODS *
 * ****************/
void Harl::debug() const
{
	std::cout
		<< "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< "I really do!\n";
}

void Harl::info() const
{
	std::cout
		<< "I cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger! "
		<< "If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning() const
{
	std::cout
		<< "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years "
		<< "whereas you started working here since last month.\n";
}

void Harl::error() const
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
