#include <map>
#include "Commands/ICommand.h"
#include "Commands/New.h"
#include "Commands/Save.h"
#include "Commands/Load.h"
#include "Commands/Quit.h"
//#include "Commands/Rename.h"
#include "Commands/Len.h"
#include "Commands/Find.h"
#include "Commands/Count.h"
#include "Commands/FindAll.h"

class CommandsCollection
{
public:
	CommandsCollection();
	~CommandsCollection();
	ICommand* getCommand(std::string string);
	
private:
	std::map<std::string, ICommand*> m_collection;
	
};

inline ICommand* CommandsCollection::getCommand(std::string string)
{
	try
	{
		if ((m_collection.find(string) == m_collection.end()))
		{
			throw dnaException("Command not found");
		}
		
	}
	catch(dnaException &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return m_collection[string];
}

inline  CommandsCollection::CommandsCollection()
{
	
	m_collection = {{"load", new Load()}, 
			{"new", new New()}, 
			{"save", new Save()}, 
			{"quit", new Quit()}, 
			//{"rename", new Rename()}, 
			{"len", new Len()},
			{"find", new Find()},
			{"count", new Count()},
			{"findall", new FindAll()}};
}

inline CommandsCollection :: ~CommandsCollection()
{
	std::map<std::string, ICommand*>::const_iterator it = m_collection.begin();
	for (; it!=m_collection.end(); ++it)
	{
		delete it->second;
	}
}

