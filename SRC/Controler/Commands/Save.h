#include "ICommand.h"
#include "../../Model/Dna/DnaCollection.h"
#include <fstream>
#include <exception>

class Save : public ICommand
{
public:
	void execute(std::vector<std::string> vec);
	~Save();
};

inline void Save::execute(std::vector<std::string> vec)
{
	try
	{
		checkInput(vec.size(), 2, 3);
		std::string nameOfFile;
		if (vec.size() == 2)
		{
			nameOfFile = vec[1];
			nameOfFile += ".rawdna";
		}
		else
		{
			nameOfFile = vec[2];
			nameOfFile += ".rawdna";
		}
		if (!DnaCollection::findName(vec[1]))
		{
			throw dnaException("Name not found");
		}
		std::ofstream file(nameOfFile.c_str());
		std::string seq;
		seq = DnaCollection::getSeqByName(vec[1]);
		file << seq;	
	}
	catch(dnaException &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}

inline Save::~Save()
{
}
