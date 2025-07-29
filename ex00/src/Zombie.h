#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

/****************
 * ZOMBIE CLASS *
 * *************/
class Zombie {
public:
	Zombie(std::string);
	~Zombie();
	void announce() const;
private:
	std::string name;
};

/************************************
 * INSTANCIATION FUNCTIONS WRAPPERS *
 * *********************************/
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
