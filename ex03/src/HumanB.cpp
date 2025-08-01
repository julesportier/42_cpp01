#include "HumanB.h"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name)
	: name(name)
{};

void HumanB::attack() const
{

	std::cout << this->name;
	if (this->w->getType().size() > 0)
		std::cout << " attacks with their " << this->w->getType();
	else
		std::cout << " don't have a weapon";
	std::cout << '\n';
}

void HumanB::setWeapon(Weapon w)
{
	std::cout << w.getType() << '\n';//<- DEBUG
	this->w = &w;
}
