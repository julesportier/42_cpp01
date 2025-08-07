#include "../src/FileBuf.h"
#include "test_print.h"
#include <iostream>

static int test_FileBuf_constructor()
{
	try {
		FileBuf fb(NULL);
	} catch (std::exception& e)  {
		print_ok_exception("Constructor doesn't accept NULL as arg", e);
	}
	try {
		FileBuf fb("no_file");
		if (fb.get_ifname() == "no_file")
			return (print_ko("Constructor open non existing file"));
	} catch (std::exception& e)  {
		print_ok_exception("Constructor don't open non existing file", e);
	}
	try {
		FileBuf fb("test/test.txt");
		if (fb.get_ifname() == "test/test.txt")
			print_ok("Constructor open existing file with right access");
	} catch (std::exception& e)  {
		return (print_ko_exception(
			"Constructor don't open existing file with right access", e));
	}
	return (0);
}

static int test_FileBuf_replace(
	std::string input_file,
	std::string search,
	std::string replace)
{
	try {
		FileBuf fb(input_file.c_str());
		int search_nbr = fb.count_str(search);
		fb.replace(search, replace);
		if (replace.size() == 0) {
			if (fb.count_str(search) == 0)
				print_ok_replace(fb, search, replace);
			else
				return (print_ko_replace(fb, search, replace));
		}
		else {
			if (search_nbr == fb.count_str(replace))
				print_ok_replace(fb, search, replace);
			else
				return (print_ko_replace(fb, search, replace));
		}
	} catch (std::exception e) {
		std::cerr << "Error on test: ifs state not good: " << e.what() << '\n';
		return (-1);
	}
	return (0);
}

static int test_FileBuf_write_disk(std::string input_file)
{
	std::string const postfix = ".replace";
	try {
		FileBuf in(input_file.c_str());
		in.write_disk();
		FileBuf out((input_file + postfix).c_str());
		print_write(input_file, (input_file + postfix));
	} catch (std::exception e) {
		std::cerr << "Error on test: ifs state not good: " << e.what() << '\n';
		return (-1);
	}
	return (0);
}

int main(void)
{
	if (test_FileBuf_constructor())
		return (-1);
	if (test_FileBuf_replace("test/test.txt", "search", "replace"))
		return (-1);
	if (test_FileBuf_replace("test/test.txt", "", "replace"))
		return (-1);
	if (test_FileBuf_replace("test/test.txt", "search", ""))
		return (-1);
	if (test_FileBuf_replace("test/test.txt", "", ""))
		return (-1);
	if (test_FileBuf_replace("test/test_except.txt", "exception", "**REPLACED**"))
		return (-1);
	if (test_FileBuf_replace("test/test_line.txt", "search", "replace"))
		return (-1);
	if (test_FileBuf_replace("test/test_line.txt", "", "replace"))
		return (-1);
	if (test_FileBuf_replace("test/test_line.txt", "search", ""))
		return (-1);
	if (test_FileBuf_replace("test/test_line.txt", "", ""))
		return (-1);
	if (test_FileBuf_replace("test/empty.txt", "search", "replace"))
		return (-1);
	if (test_FileBuf_replace("test/empty.txt", "", "replace"))
		return (-1);
	if (test_FileBuf_replace("test/empty.txt", "search", ""))
		return (-1);
	if (test_FileBuf_replace("test/empty.txt", "", ""))
		return (-1);
	if (test_FileBuf_replace("test/empty.txt", "", ""))
		return (-1);
	if (test_FileBuf_replace("test/0.txt", "0", "00"))
		return (-1);
	if (test_FileBuf_write_disk("test/test.txt"))
		return (-1);
	if (test_FileBuf_write_disk("test/test_line.txt"))
		return (-1);
	if (test_FileBuf_write_disk("test/empty.txt"))
		return (-1);
	return (0);
}
