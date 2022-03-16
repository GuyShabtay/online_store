/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __READINGBOOKS_H__
#define __READINGBOOKS_H__
#include "books.h"
#include <iostream> 
using namespace std;

class ReadingBooks : virtual public Books
{
private:
	char* janer;

public:
	char* getJaner() { return janer; }
	virtual void priceCalculate();
	ReadingBooks(char* name, int  pages, int outYear, char* janer);
	~ReadingBooks();
	virtual const char* getType() const { return "Reading Book"; }
	virtual void toOs(ostream& os) const;
	virtual Store* clone() const { return new ReadingBooks(*this); }

	ReadingBooks(const ReadingBooks& other);
};
#endif __READINGBOOKS_H__


