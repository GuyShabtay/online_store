#pragma once
/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __BOOKS_H__
#define __BOOKS_H__
#include "store.h"

using namespace std;

class Books :virtual public Store
{
protected:
	int pages;
public:
	int getPages() { return pages; }
	Books(int pages);
	virtual void priceCalculate() = 0;
	~Books();
	Books();


};
#endif __BOOKS_H__
