#include <string>
#include <fstream>

class FileBuf {
public:
	FileBuf(char const* ifname);
	void replace(std::string search, std::string replace);
	void write_disk();
private:
	std::string const ifname;
	std::ifstream ifs;
	std::string buffer;
	int check_ifs_state(std::ifstream& ifs);
	void fill_buffer();
	std::string get_replace_filename();
	int check_ofs_state(std::ofstream& ofs);
};
