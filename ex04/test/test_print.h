#include "../src/FileBuf.h"

void print_ok(std::string message);
void print_ok_exception(std::string message, std::exception& e);
int print_ko(std::string message);
int print_ko_exception(std::string message, std::exception& e);
void print_ok_replace(
	FileBuf& fb,
	std::string search,
	std::string replace);
int print_ko_replace(
	FileBuf& fb,
	std::string search,
	std::string replace);
int print_write(std::string input, std::string output);
