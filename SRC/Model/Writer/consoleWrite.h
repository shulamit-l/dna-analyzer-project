#ifndef __CONSOLE_WRITER_H__
#define __CONSOLE_WRITER_H__

#include <string>
#include "IWriter.h"

class ConsoleWrite : public IWriter
{
public:
	~ConsoleWrite();
	void write(std::string);
};

inline void ConsoleWrite::write(std::string str)
{
	std::cout<<str<<std::endl;
}
inline ConsoleWrite:: ~ConsoleWrite()
{
}

#endif //__CONSOLE_WRITER_H__
