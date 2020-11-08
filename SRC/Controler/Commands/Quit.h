#include "ICommand.h"

class Quit : public ICommand
{
public:
	void execute(std::vector<std::string> vec);
	~Quit();
};


inline void Quit::execute(std::vector<std::string> vec)
{
	std::cout<<"Are you sure you want to quit?"<<std::endl;
	std::cout<<"Please confirm by 'y' or cancle by 'n'"<<std::endl;
	std::string confirm;
	getline(std::cin, confirm);
	if (confirm == "y")
	{
		std::cout<<"Thank you for using DnaAnalyzer"<<std::endl;
		std::cout<<"Goodbye!"<<std::endl;
		exit(0);
	}
	
}

inline Quit::~Quit()
{
}

