/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __KIDSBOOKS_H__
#define __KIDSBOOKS_H__
#include "books.h"
#include "store.h"
#include <iostream> 
using namespace std;

class KidsBooks :virtual public Books
{
private:
	int minAge;
public:
	KidsBooks(char* name, int pages, int outYear, int minAge);

	virtual void priceCalculate();
	virtual void toOs(ostream& os) const;
	virtual const char* getType() const { return "Children Book"; }

	virtual Store* clone() const { return new KidsBooks(*this); }
	KidsBooks(const KidsBooks& other);//copy Ctor that creats the new string dinamiclly

};
#endif __KIDSBOOKS_H__


