#ifndef __INVALIDNUC_H__
#define __INVALIDNUC_H__
#include "stdio.h"
#include <iostream>
#include<cstring>
#include<stdexcept>
class InvalidNucleotide:public std::invalid_argument
{
public:
	InvalidNucleotide();
	const char* what() const throw();
};
inline InvalidNucleotide::InvalidNucleotide():std::invalid_argument(""){}
inline const char* InvalidNucleotide::what() const throw()
{
	return "invalid dna";
}
#endif //__INVALIDNUC_H__
