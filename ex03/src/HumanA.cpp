#include "HumanA.h"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon& w)
	: name(name), w(w)
{};

void HumanA::attack() const
{
	std::cout
		<< this->name
		<< " attacks with their "
		<< this->w.getType()
		<< '\n';
}

