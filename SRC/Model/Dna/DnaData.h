#ifndef __DNADATA_H__
#define __DNADATA_H__

#include "DnaSequence.h"

class DnaData
{
public:
	DnaData(std::string, std::string);
	DnaData(std::string, std::string, size_t id);
	DnaSequence& getSequence();
	std::string getName();
	size_t getId();
	
	
		
private:
	DnaSequence* m_sequence;
	std::string m_name;
	size_t m_id;
	static size_t s_idCount ;
	
	
};


inline DnaData :: DnaData(std::string sequence, std::string name) : m_name(name) , m_id(s_idCount)
{	
	m_sequence = new DnaSequence(sequence);
	s_idCount++;
}

inline DnaData :: DnaData(std::string sequence, std::string name, size_t id) : m_name(name) , m_id(id)
{	
	m_sequence = new DnaSequence(sequence);
	
}

inline std::string DnaData::getName()
{
	return m_name;
}
inline size_t DnaData::getId()
{
	return m_id;
}
inline DnaSequence& DnaData::getSequence()
{
	return *m_sequence;
}

#endif //__DNADATA_H__
