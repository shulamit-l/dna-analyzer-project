#include "ICommand.h"
#include "../../Model/Dna/DnaCollection.h"
#include "auxiliaryFuncs.h"

class Find : public ICommand
{
public:
	void execute(std::vector<std::string> vec);
	~Find();
};


inline void Find::execute(std::vector<std::string> vec)
{
	try
	{
		checkInput(vec.size(), 3, 3);
		if (vec[1][0] != '#')
		{
			throw  dnaException("Please enter # befor id");
		}
		std::string str1;
		std::string str2;
		vec[1].erase(0, 1);
		if (!(DnaCollection::findId(stoi(vec[1]))))
		{
			throw  dnaException("Invalid id");
		}
		str1 = DnaCollection::getSeqById(stoi(vec[1]));
		if (vec[2][0] == '#')
		{
			vec[2].erase(0, 1);
			if(!DnaCollection::findId(stoi(vec[2])))
			{
				throw  dnaException("Invalid id");
			}
			str2 = DnaCollection::getSeqById(stoi(vec[2]));
		}
		else 
		{
			DnaSequence seq(vec[2]);
			str2 = seq.getSequenceAsString();	
		}
		if (str1.find(str2) != std::string::npos)
		{
			std::cout<<str1.find(str2)<<std::endl;
		}
		else
		{
			std::cout<<str2<<" not in "<<str1<<std::endl;
		}
	}
	catch(dnaException &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}

inline Find::~Find()
{
}
