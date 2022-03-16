
/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __ACTION_H__
#define __ACTION_H__
#include "movies.h"
#include <iostream> 
using namespace std;

class Action : public Movies
{
private:
public:
	Action(char* name, int  outYear, int level);
	bool levelSelect(int level);
	virtual void toOs(ostream& os) const;
	virtual const char* getType() const { return "Action Movie"; }
	virtual Store* clone() const { return new Action(*this); }

	Action(const Action& other);

};
#endif __ACTION_H__