
#ifndef __ICOMMAND_H__
#define __ICOMMAND_H__
#include <vector>
#include "../../Model/Dna/DnaData.h"

//----------------------InterfaceOfCommands-------------------

class ICommand
{
public:
	virtual void execute(std::vector<std::string> vec) = 0;
	virtual ~ICommand(){};
};


#endif







