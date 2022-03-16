/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __THRILLER_H__
#define __THRILLER_H__
#include "movies.h"
#include <iostream> 
using namespace std;

class Thriller : public Movies
{
private:

public:
	Thriller(char* name, int  outYear, int level);
	virtual bool levelSelect(int level);
	virtual void toOs(ostream& os) const;
	virtual const char* getType() const { return "Thriller Movie"; }
	virtual Store* clone() const { return new Thriller(*this); }

	Thriller(const Thriller& other);
};
#endif __THRILLER_H__

