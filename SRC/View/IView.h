#ifndef __IVIEW_H__
#define __IVIEW_H__

#include "../Controler/CommandCollection.h"
#include "../Model/Reader/IReader.h"
#include "../Model/Writer/IWriter.h"
//-----------------------InterfaceOfView------------------

class IView
{
public:
	virtual void execCommand(CommandsCollection& collection, IReader& reader, IWriter& writer) = 0;
	virtual ~IView(){};
	
};

#endif //__IVIEW_H__



