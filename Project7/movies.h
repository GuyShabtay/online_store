/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __MOVIES_H__
#define __MOVIES_H__
#include "store.h"
using namespace std;

class Movies :virtual public Store
{
protected:
	int level;
public:
	Movies(int level);
	Movies();
	void priceCalculate();
	virtual ~Movies() = 0;
	virtual bool levelSelect(int level) = 0;


};
#endif __MOVIES_H__
