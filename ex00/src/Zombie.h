#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

/****************
 * ZOMBIE CLASS *
 * *************/
class Zombie {
public:
	Zombie();
	~Zombie();
	void announce() const;
	void set_name(std::string name);
private:
	std::string name;
};

/************************************
 * INSTANCIATION FUNCTIONS WRAPPERS *
 * *********************************/
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
