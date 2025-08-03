#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.h"
# include <string>

class HumanB
{
public:
	HumanB(std::string name);
	void attack() const;
	void setWeapon(Weapon& weapon);
private:
	std::string const name;
	Weapon* w;
};

#endif
