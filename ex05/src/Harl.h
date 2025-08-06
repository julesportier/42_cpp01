#ifndef HARL_H
# define HARL_H

# include <string>


class Harl {
public:
	void complain(std::string level) const;
private:
	void debug() const;
	void info() const;
	void warning() const;
	void error() const;
};

typedef void (Harl::*harl_fn)() const;

struct harl_map {
	std::string level;
	harl_fn f_ptr;
};

#endif
