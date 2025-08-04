#include "FileBuf.h"
#include <iostream>
#include <sstream>

/******************
 * PUBLIC METHODS *
 * ***************/
// The constructor saves the content of the input file
// in a string buffer for later manipulation.
FileBuf::FileBuf(char const* ifname) : ifname(ifname)
{
	ifs.open(ifname);
	if (check_ifs_state(ifs)) {
		ifs.close();
		throw (-1);
	}
	fill_buffer();
	// std::cout << buffer;
	ifs.close();
};

void FileBuf::replace(std::string search, std::string replace)
{
	std::string::size_type search_size = search.size();
	if (search_size == 0) {
		return ;
	}
	std::string::size_type pos = 0;
	while ((pos = this->buffer.find(search)) != std::string::npos) {
		this->buffer.erase(pos, search_size);
		this->buffer.insert(pos, replace);
	}
	std::cout << this->buffer;
};

/*******************
 * PRIVATE METHODS *
 * ****************/
int FileBuf::check_ifs_state(std::ifstream& ifs)
{
	if (ifs.good())
		return (0);
	else {
		std::cerr << "Error trying to read the input file\n";
		return (-1);
	}
}

void FileBuf::fill_buffer()
{
	std::stringstream s_str;
	s_str << ifs.rdbuf();
	buffer = s_str.str();
}
