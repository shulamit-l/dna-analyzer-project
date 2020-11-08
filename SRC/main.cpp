#include <iostream>
#include "Controler/Manager.h"
#include "View/CommandLine.h"
#include "Model/Dna/DnaSequence.h"
#include "Model/Reader/consoleRead.h"
#include "Model/Writer/consoleWrite.h"



size_t DnaData::s_idCount = 1;
size_t New::numOfSeq = 0;
std::map<size_t,std::string> DnaCollection::m_map1 = {};
std::map<std::string, DnaData*> DnaCollection::m_map2 = {};
int main()
{
	CLI cli;
	ConsoleWrite writer;
	ConsoleRead reader;
	Manager manager(cli, reader, writer);
	manager.run();

	return 0;
}
