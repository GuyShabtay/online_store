/* Assignment: 3
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __STORE_H__
#define __STORE_H__
#include <iostream> 
using namespace std;

class Store
{
protected:
	float price;
	static long counter;
	long serialNumber;
	char* name;
	int outYear;
public:

	float getPrice() { return price; }
	char* getName() { return name; }
	long getSerialNumber();
	void setSerialNumber(long serialNumber);
	void setSerialNumber1();
	Store(char* name, int outYear);
	virtual ~Store() = 0;
	Store();
	virtual void priceCalculate() = 0;
	virtual const char* getType() const { return "store"; }
	friend ostream& operator<<(ostream& os, Store& printer);
	virtual void toOs(ostream& os) const {}
	bool operator==(char* other) const;//operator ==

	virtual Store* clone() const = 0;
};
#endif __STORE_H__
