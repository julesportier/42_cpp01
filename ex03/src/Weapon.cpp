#include <string>
#include "Weapon.h"

Weapon::Weapon(std::string type) : type(type) {};

std::string const& Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
