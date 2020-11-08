#ifndef __AUXILIARY_FUNCS_H__
#define __AUXILIARY_FUNCS_H__

#include "../../Model/Dna/dnaException.h"
#include "../../Model/Dna/DnaSequence.h"


inline void printSeq(std::string name, std::string seq, size_t id)
{
	if (seq.length()>=40)
	{
		std::cout<<"["<<id<<"] "<<name<<": "<<seq.substr(0, 31)<<"..."<<seq.substr(seq.length()-3, seq.length())<<std::endl;
	}
	else
	{
		std::cout<<"["<<id<<"] "<<name<<": "<<seq<<std::endl;
	}
}

inline void checkInput(int size, int min, int max)
{
	if (size > max)
	{
		throw dnaException("too many arguments");
	}
	if (size < min)
	{
		throw dnaException("too few arguments");
	}
}

/*inline bool checkSeq(std::string str)
{
	for (int i = 0; i<str.size(); i++)
	{
		if (!(DnaSequence::check(str[i])))
		{
			throw dnaException("Invalid dna");
		}
	}
	return true;
}*/

#endif //__AUXILIARY_FUNCS_H__
