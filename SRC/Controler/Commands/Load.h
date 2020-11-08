#include <fstream>
#include "ICommand.h"
#include "auxiliaryFuncs.h"

class Load : public ICommand
{
public:
	void execute(std::vector<std::string> vec);
	~Load();
};


inline void Load::execute(std::vector<std::string> vec)
{
	try
	{
		checkInput(vec.size(), 2, 2);
		std::ifstream input (vec[1]);
		std::string seq;
		std::getline(input, seq);
		size_t latsIndex = vec[1].find_last_of(".");
		std::string rawname = vec[1].substr(0, latsIndex);
		DnaData* dna = new DnaData(seq, rawname);
		DnaCollection::addDna(dna);
		printSeq(rawname, seq, dna->getId());
		
	}
	catch(dnaException &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	
}

inline Load::~Load()
{
}

