#include "ICommand.h"
#include "../../Model/Dna/DnaCollection.h"
#include "auxiliaryFuncs.h"

class Len : public ICommand
{
public:
	void execute(std::vector<std::string> vec);
	~Len();
};

inline void Len::execute(std::vector<std::string> vec)
{
	try
	{
		checkInput(vec.size(), 2, 2);
		std::string name;
		if (vec[1][0] != '#')
		{
			throw dnaException("Invalid id");
		}
		vec[1].erase(0, 1);
		size_t id = stoi(vec[1]);
		if (!DnaCollection::findId(id))
		{
			throw dnaException("Invalid id");
		}
		name = DnaCollection::getSeqById(id);
		std::cout<<DnaCollection::getSeqByName(name).size()<<std::endl;
	}
	catch(dnaException &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}

inline Len::~Len()
{
}
