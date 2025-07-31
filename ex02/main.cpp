#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "str address:            " << &str << '\n';
	std::cout << "stringPTR held address: " << stringPTR << '\n';
	std::cout << "stringREF held address: " << &stringREF << '\n';

	std::cout << "str value:               " << str << '\n';
	std::cout << "stringPTR pointed value: " << *stringPTR << '\n';
	std::cout << "stringREF pointed value: " << stringREF << '\n';

	return (0);
}
