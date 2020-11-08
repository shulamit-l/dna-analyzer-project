#ifndef __READER_H__
#define __READER_H__

class IReader
{
public:
	virtual ~IReader(){};
	virtual std::string read() = 0;
};

#endif // __READER_H__
