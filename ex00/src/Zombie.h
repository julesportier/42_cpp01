#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

class Zombie {
public:
	Zombie(std::string);
	~Zombie();
	void announce() const;
private:
	std::string name;
};

#endif
