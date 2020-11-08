#include <iostream>
#include "IReader.h"

class ConsoleRead : public IReader
{
public:
	~ConsoleRead();
	std::string read();
};
inline std::string ConsoleRead::read()
{
	std::cout<<"> cmd >>> ";
	std::string input;
	getline(std::cin, input);
	return input;
}
inline ConsoleRead:: ~ConsoleRead()
{
}
