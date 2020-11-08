#ifndef __WRITER_H__
#define __WRITER_H__


class IWriter
{
public:
	virtual ~IWriter(){};
	virtual void write(std::string) = 0;
};


#endif //__WRITER_H__
