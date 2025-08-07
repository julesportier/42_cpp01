#ifndef FILEBUF_H
# define FILEBUF_H

# include <string>
# include <fstream>

class FileBuf {
public:
	FileBuf(char const* ifname);
	void replace(std::string search, std::string replace);
	void write_disk();
	std::string get_ifname() const;
	int count_str(std::string str) const;
	std::string get_buffer() const;
private:
	std::string const ifname;
	std::ifstream ifs;
	std::string buffer;
	void fill_buffer();
	std::string get_replace_filename();
};

#endif
