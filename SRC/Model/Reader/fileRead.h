#include <iostream>
#include "IReader.h"

class FileReader : public IReader
{
public:
	FileReader(std::string);
	~FileReader();
	std::string read();
	
private:
	std::string m_fileName;
};
inline FileReader::FileReader(std::string fileName):m_fileName(fileName)
{
	
}
inline std::string FileReader::read()
{
	std::ifstream file(m_fileName);
	std::string line;
	std::getline(file, line);

	return line;
}
inline FileReader:: ~FileReader()
{
}
