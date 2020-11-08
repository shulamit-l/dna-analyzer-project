#include "IView.h"

class CLI : public IView
{
public:
	void execCommand(CommandsCollection& collection, IReader& reader, IWriter& writer);
	~CLI();

private:
	ICommand* m_command;
	
	
	std::vector<std::string> cutInput(std::string str);
};



inline void CLI::execCommand(CommandsCollection& collection, IReader& reader, IWriter& writer)
{
	std::string input;
	input = reader.read();
	std::vector<std::string> commandVec = cutInput(input);
	std::string command = commandVec[0];
	while (true)
	{
		collection.getCommand(command) -> execute(commandVec);
		input = reader.read();
	 	commandVec = cutInput(input);
		command = commandVec[0];
	}
	
	
}



inline std::vector<std::string> CLI::cutInput(std::string str)
{
	std::vector<std::string> inputVec;
	int counter = -1;
	std::string delimiter = " ";
	for (size_t i = 0; i<str.length();)
	{
		inputVec.push_back(str.substr(i, (str.find(delimiter,i+1)-i)));
		counter++;
		i+=inputVec[counter].length()+1;
	}
	return inputVec;
}

inline CLI::~CLI()
{
}
