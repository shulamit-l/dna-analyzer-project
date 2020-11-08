#include "../View/IView.h"
#include "../Model/Reader/IReader.h"

class Manager
{
private:
	IView* m_view;
	IReader* m_reader;
	IWriter* m_writer;
public:
	Manager(IView& view, IReader& reader, IWriter& writer);
	void run();
	void shutDown();
};

inline Manager::Manager(IView& view, IReader& reader, IWriter& writer):m_view(&view), m_reader(&reader), m_writer(&writer)
{
	
}

inline void Manager::run()
{
	CommandsCollection collection;
	m_view -> execCommand(collection,*m_reader, *m_writer );
}

inline void Manager::shutDown()
{

}
