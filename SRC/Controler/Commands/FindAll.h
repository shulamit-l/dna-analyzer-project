#include "ICommand.h"
#include "../../Model/Dna/DnaCollection.h"
#include "auxiliaryFuncs.h"

class FindAll : public ICommand
{
public:
	void execute(std::vector<std::string> vec);
	~FindAll();
};

inline void FindAll::execute(std::vector<std::string> vec)
{
	try
	{
		checkInput(vec.size(), 3, 3);
		if (vec[1][0] != '#')
		{
			throw  dnaException("Please enter # befor id");
		}
		vec[1].erase(0, 1);
		std::string str1;
		std::string str2;
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
		const size_t step = str2.size();
		size_t pos = 0;
		while ((pos = str1.find(str2, pos)) != std::string::npos )
		{
			std::cout<<pos<<" ";
			pos += step;
		}
		std::cout<<""<<std::endl;
	}
	catch(dnaException &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}

inline FindAll::~FindAll()
{
}
