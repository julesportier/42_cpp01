#include <string>
#include <fstream>

class FileBuf {
public:
	FileBuf(char const* ifname);
	void replace(std::string search, std::string replace);
	int write(std::string ofname);
private:
	std::string const ifname;
	std::ifstream ifs;
	std::string buffer;
	int check_ifs_state(std::ifstream& ifs);
	void fill_buffer();
};
