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
	if (!ifs.good()) {
		ifs.close();
		throw (std::ios_base::failure("Error opening input file"));
	}
	fill_buffer();
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
};

void FileBuf::write_disk()
{
	std::ofstream ofs(this->get_replace_filename().c_str(), std::ios::trunc);
	if (!ofs.good()) {
		ofs.close();
		throw (std::ios_base::failure("Error opening output file"));
	}
	ofs << this->buffer.c_str();
	ofs.close();
}

/*******************
 * PRIVATE METHODS *
 * ****************/
void FileBuf::fill_buffer()
{
	std::stringstream s_str;
	s_str << ifs.rdbuf();
	buffer = s_str.str();
}

std::string FileBuf::get_replace_filename()
{
	std::string name = this->ifname;
	return (name.append(".replace"));
}
