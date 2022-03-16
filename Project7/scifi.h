/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __SCIFI_H__
#define __SCIFI_H__
#include "movies.h"
#include <iostream> 
using namespace std;

class SciFi : public Movies
{
private:

public:
	SciFi(char* name, int  outYear, int level);
	bool levelSelect(int level);
	virtual void toOs(ostream& os) const;
	virtual const char* getType() const { return "Sci-Fi Movie"; }
	virtual Store* clone() const { return new SciFi(*this); }

	SciFi(const SciFi& other);
};
#endif __SCIFI_H__

