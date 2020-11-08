#include <exception>

#include "ICommand.h"
#include "../../Model/Dna/DnaCollection.h"
#include "../../Model/Dna/DnaSequence.h"
#include "../../Model/Dna/dnaException.h"
#include "auxiliaryFuncs.h"
class New : public ICommand
{
private:
	static size_t numOfSeq;
public:
	void execute(std::vector<std::string> vec);
	~New();
};

inline void New::execute(std::vector<std::string> vec)
{
	try
	{
		checkInput(vec.size(), 2, 3);
		if (vec.size() == 2)
		{
			char buffer[20];
			sprintf(buffer, "seq_%ld", numOfSeq++);
			DnaData* dna = new DnaData(vec[1],buffer);
			DnaCollection::addDna(dna);
			printSeq(dna->getName(),vec[1], dna->getId());
			
		}
		else 
		{
			if (vec[2][0] != '@')
			{
				throw  dnaException("Invalid Nucleotide");
			}
			vec[2].erase(0, 1);
			DnaData* dna = new DnaData(vec[1],vec[2]);
			DnaCollection::addDna(dna);
			printSeq(dna->getName(),vec[1], dna->getId());
		}
	}
	catch(dnaException &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	
}

inline New::~New()
{
}
