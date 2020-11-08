#ifndef __DNASEQUENCE_H__
#define __DNASEQUENCE_H__
#include "../../Controler/Commands/auxiliaryFuncs.h"
#include <cstring>

class DnaSequence
{
private:
	class Nucleotide
	{
	public:
		Nucleotide(){}
		//Nucleotide(const char& dna);
		Nucleotide& operator = (const char& dna);
		char get_char()const;
		
		
	private:
		char m_char;
	};
	

public:
	DnaSequence(const std::string& dna);
	//DnaSequence& operator = (const DnaSequence& dna);
	const DnaSequence::Nucleotide *getDna()const;
	size_t len()const;
	DnaSequence::Nucleotide& operator [](const size_t ind)const;
	std::string getSequenceAsString();
	Nucleotide* m_dna;
	static bool check(const char str);
	friend std::ostream& operator << (std::ostream& cout,const DnaSequence::Nucleotide& dna);
	friend std::ostream& operator << (std::ostream& cout,const DnaSequence& dna);	
	
};

inline bool DnaSequence::check(const char str)
{
	char ch = tolower(str);
	if ((ch != 'a') & (ch != 'g') & (ch != 'c') & (ch != 't'))
	{
		return false;
	}
	return true;
}
inline std::string DnaSequence::getSequenceAsString()
{
	std::string sequence;
	for(size_t i=0;i<len();i++)
	{
		sequence+=(*this)[i].get_char();
	}
	return sequence;
}
inline DnaSequence::Nucleotide& DnaSequence::Nucleotide::operator = (const char& dna)
{
	if(check(dna)==false)
	{
		throw dnaException("Invalid Nucleotide");
	}
	m_char=dna;
		
	
	return *this;
}
inline DnaSequence::DnaSequence(const std::string& dna)
{
	m_dna=new Nucleotide[strlen(dna.c_str())];
	for(size_t i=0;i<strlen(dna.c_str());i++)
	{
		m_dna[i]=dna[i];
	}
}



inline DnaSequence::Nucleotide& DnaSequence::operator [] (const size_t ind)const
{
			
	return m_dna[ind];
}

inline const DnaSequence::Nucleotide* DnaSequence::getDna()const
{
	return m_dna;
}
inline size_t DnaSequence::len()const
{
	size_t i=0;
	while(m_dna[i].get_char()!='\0')
	{
		i++;
	}
	return i;
}
inline char DnaSequence::Nucleotide::get_char()const
{
	return m_char;
}
inline std::ostream& operator << (std::ostream& cout,const DnaSequence& dna)
{
	std::cout<<"I'm hear"<<std::endl;
	for(size_t i=0;i<dna.len();i++)
	{
		std::cout<<dna[i].get_char();
	}
	return cout;
}
#endif //__DNASEQUENCE_H__
