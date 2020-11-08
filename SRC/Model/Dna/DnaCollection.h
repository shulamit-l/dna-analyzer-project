#ifndef __DNACOLLECTION_H__
#define __DNACOLLECTION_H__

#include <map>
#include "DnaData.h"

class DnaCollection
{
public:
	static bool findName(std::string str);
	static bool findId(size_t id);
	static void addDna(DnaData*);
	static std::string getSeqByName(std::string name);
	static std::string getSeqById(size_t id);
private:
	static std::map<size_t,std::string> m_map1;
	static std::map<std::string, DnaData*> m_map2;
	
};


inline bool DnaCollection::findName(std::string str)
{
	return !(m_map2.find(str) == m_map2.end());
}
inline bool DnaCollection::findId(size_t id)
{
	return !(m_map1.find(id) == m_map1.end());
}

inline void DnaCollection::addDna(DnaData* dna)
{
	m_map1.insert({dna->getId(), dna->getName()});
	m_map2.insert({dna->getName(), dna});
	/*std::map<std::string, DnaData*>::const_iterator it = m_map2.begin();
	for (;it!=m_map2.end();it++)
	{
		std::cout<<it->first<<std::endl;
		std::cout<<(it->second)->getSequence().getSequenceAsString()<<std::endl;
		//std::cout<<(it->second)->getSequence().getSequenceAsString()<<std::endl;
	}*/
}

inline std::string DnaCollection::getSeqByName(std::string name)
{
	return m_map2[name]->getSequence().getSequenceAsString();
}

inline std::string DnaCollection::getSeqById(size_t id)
{
	return m_map2[m_map1[id]]->getSequence().getSequenceAsString();
}


#endif //DNACOLLECTION	
	
