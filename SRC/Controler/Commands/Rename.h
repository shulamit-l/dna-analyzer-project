#include "ICommand.h"
#include "../../Model/Dna/DnaCollection.h"

class Rename : public ICommand
{
public:
	void execute(std::vector<std::string> vec);
	~Rename();
};

inline void Rename::execute(std::vector<std::string> vec)
{
	try
	{
		checkInput(vec.size(), 3, 3);
		vec[2].erase(0, 1);
		if (DnaCollection::findName(vec[2]))
		{
			throw dnaException("Name already exists");
		}
		std::string name;
		size_t id = 0;
		bool flag = false;
		std::map<std::string, DnaData*>:: iterator it = DnaCollection::m_map2.begin();
		for(it; it!=DnaCollection::m_map2.end(); it++)
		{
			if (it->second -> getSequence().getSequenceAsString() == vec[1])
			{
				id = it->second ->getId();
				name = it->second ->getName();
				flag = true;
				break;
				
				
			}
			
		}
		if (!flag)
		{
			throw dnaException("Sequence not found");
		}
		std::map<size_t, std::string>:: iterator itr = DnaCollection::m_map1.find(id);
		DnaCollection::m_map1.erase(itr);
		std::map<std::string, DnaData*>:: iterator ito = DnaCollection::m_map2.find(name);
		DnaCollection::m_map2.erase(ito);
		DnaData* dna = new DnaData(vec[1],vec[2], id);
		DnaCollection::addDna(dna);
		printSeq(dna->getName(), dna->getSequence().getSequenceAsString(), dna->getId());
		
		
		
	}
	catch(dnaException &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}

inline Rename :: ~Rename()
{
}
