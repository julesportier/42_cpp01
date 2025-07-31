#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.h"
# include <string>

class HumanA
{
public:
	HumanA(std::string name, Weapon& w);
	void attack() const;
private:
	std::string const name;
	Weapon& w;
};

#endif
