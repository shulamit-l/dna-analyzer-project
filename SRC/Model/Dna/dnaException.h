#ifndef __DNA_EXCEPTION_H__
#define __DNA_EXCEPTION_H__

#include <exception>
#include <string>

class dnaException : public std::exception
{
public: 
	dnaException(std::string s);
	const char* what() const throw();
	
private:
	std::string m_sentence;
};

inline dnaException::dnaException(std::string s):m_sentence{s}{}
inline const char* dnaException::what() const throw()
{
	return m_sentence.c_str();
}

#endif //__DNA_EXCEPTION_H__
